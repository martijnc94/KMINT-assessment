#include <kmint/pigisland/math.h>
#include "SteeringBehaviors.h"
#include "kmint/pigisland/actor/pig.hpp"
#include <kmint/pigisland/actor/shark.hpp>

kmint::pigisland::SteeringBehaviors::SteeringBehaviors(pig &actor, std::vector<Obstacle *> &obstacles) : actor(actor), obstacles(obstacles) {}

kmint::math::vector2d kmint::pigisland::SteeringBehaviors::calculate()
{
    auto res = math::vector2d{};
    math::vector2d boatLocation = actor.getBoat().location();
    math::vector2d sharkLocation = actor.getShark().location();

    math::vector2d forceToBoat{};
    if (actor.getGeneticAttributes().getAttractionToPorcusVictus() != 0) {
        forceToBoat += seek(boatLocation);
        forceToBoat += arrive(boatLocation, slow);
        forceToBoat *= actor.getGeneticAttributes().getAttractionToPorcusVictus();
    }

    math::vector2d forceToShark{};
    if (actor.getGeneticAttributes().getAttractionToKnabbel() != 0) {
        forceToShark += seek(sharkLocation);
        forceToShark += arrive(sharkLocation, slow);
        forceToShark *= actor.getGeneticAttributes().getAttractionToKnabbel();
    }

    math::vector2d cohesionForce{};
    if (actor.getGeneticAttributes().getCohesion() != 0) {
        cohesionForce += cohesion();
        cohesionForce *= actor.getGeneticAttributes().getCohesion();
    }

    math::vector2d separationForce{};
    if (actor.getGeneticAttributes().getSeparation() != 0) {
        separationForce += separation();
        separationForce *= actor.getGeneticAttributes().getSeparation();
    }

    math::vector2d alignmentForce{};
    if (actor.getGeneticAttributes().getAlignment() != 0) {
        alignmentForce += alignment();
        alignmentForce *= actor.getGeneticAttributes().getAlignment();
    }

    res += forceToBoat;
    res += forceToShark;
    res += cohesionForce;
    res += separationForce;
    res += alignmentForce;

    return res;
}

kmint::math::vector2d kmint::pigisland::SteeringBehaviors::seek(kmint::math::vector2d &targetPos)
{
    auto tmp = targetPos - actor.location();
    auto desiredVelocity = normalize(tmp) * actor.getMaxSpeed();

    return (desiredVelocity - actor.getVelocity());
}

kmint::math::vector2d
kmint::pigisland::SteeringBehaviors::arrive(kmint::math::vector2d &target, Deceleration deceleration)
{
    auto toTarget = target - actor.location();
    auto distance = vectorLength(toTarget);

    if (distance > 0) {
        const double DecelerationTweaker = 0.3;
        double speed = distance / ((double) deceleration * DecelerationTweaker);

        speed = std::min(speed, actor.getMaxSpeed());

        auto desiredVelocity = toTarget * speed / distance;

        return (desiredVelocity - actor.getVelocity());
    }

    return math::vector2d{0, 0};
}

kmint::math::vector2d kmint::pigisland::SteeringBehaviors::cohesion()
{
    math::vector2d centerOfMass, steeringForce;

    int neighborCount = 0;

    for (auto i = actor.begin_perceived(); i != actor.end_perceived(); ++i) {
        auto& f = *i;
        if (auto o = dynamic_cast<pig*>(&f); o) {
            if (o != &actor) {
                centerOfMass += o->location();
                ++neighborCount;
            }
        }
    }

    if (neighborCount > 0) {
        centerOfMass /= neighborCount;

        steeringForce = seek(centerOfMass);
    }

    return steeringForce;
}

kmint::math::vector2d kmint::pigisland::SteeringBehaviors::separation()
{
    math::vector2d steeringForce;

    for (auto i = actor.begin_perceived(); i != actor.end_perceived(); ++i) {
        auto &f = *i;
        if (auto o = dynamic_cast<pig *>(&f); o) {
            auto toAgent = actor.location() - o->location();

            steeringForce += vectorNormalize(toAgent) / vectorLength(toAgent);
        }
    }

    return steeringForce;
}

kmint::math::vector2d kmint::pigisland::SteeringBehaviors::alignment()
{
    math::vector2d averageHeading;
    int neighborCount = 0;

    for (auto i = actor.begin_perceived(); i != actor.end_perceived(); ++i) {
        auto &f = *i;
        if (auto o = dynamic_cast<pig *>(&f); o) {
            averageHeading += o->getHeading();
            ++neighborCount;
        }
    }

    if (neighborCount > 0) {
        averageHeading /= neighborCount;
        averageHeading -= actor.getHeading();
    }

    return averageHeading;
}

void kmint::pigisland::SteeringBehaviors::enforceNonPenetrationConstraint()
{
    for (auto i = actor.begin_perceived(); i != actor.end_perceived(); ++i) {
        auto &f = *i;
        if (auto o = dynamic_cast<pig *>(&f); o) {
            if (o == &actor) {
                continue;
            }

            auto toEntity = actor.location() - o->location();
            auto distanceToEachOther = vectorLength(toEntity);

            auto amountOfOverLap = o->radius() + actor.radius() - distanceToEachOther;

            if (amountOfOverLap > 0) {
                auto newLoc = actor.location() + (toEntity / distanceToEachOther) * amountOfOverLap;
                actor.setLocation(newLoc);
            }
        }
    }
}

//kmint::math::vector2d kmint::pigisland::SteeringBehaviors::obstacleAvoidance(const Obstacle& o)
//{
//    const double panicDistanceSquared = ISLANDAVOIDANCEDISTANCE * ISLANDAVOIDANCEDISTANCE;
//    if (vectorDistanceSquared(actor.location(), o.center) > panicDistanceSquared) {
//        return math::vector2d{0, 0};
//    }
//
//    math::vector2d desiredVelocity = vectorNormalize(actor.location() - o.center) * actor.getMaxSpeed();
//
//    return (desiredVelocity - actor.getVelocity());
//}
