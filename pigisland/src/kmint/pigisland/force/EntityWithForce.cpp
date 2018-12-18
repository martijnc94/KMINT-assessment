#include <kmint/pigisland/math.h>
#include "EntityWithForce.h"
#include "kmint/math/angle.hpp"
#include "kmint/random.hpp"

kmint::pigisland::EntityWithForce::EntityWithForce(math::vector2d location): free_roaming_actor(location)
{

}

double kmint::pigisland::EntityWithForce::getMass() const
{
    return mass;
}

void kmint::pigisland::EntityWithForce::setMass(double mass)
{
    EntityWithForce::mass = mass;
}

const kmint::math::vector2d &kmint::pigisland::EntityWithForce::getVelocity() const
{
    return velocity;
}

void kmint::pigisland::EntityWithForce::setVelocity(const delta_time dt)
{
    auto seconds = to_seconds(dt);
    auto v = (velocity + acceleration) * seconds;
    auto l = vectorLength(v);
    if (l <= maxSpeed) {
        velocity = v;
    } else {
        velocity = v / l * maxSpeed;
    }
}

const kmint::math::vector2d &kmint::pigisland::EntityWithForce::getHeading() const
{
    return heading;
}

void kmint::pigisland::EntityWithForce::setHeading(const kmint::math::vector2d &heading)
{
    EntityWithForce::heading = heading;
}

double kmint::pigisland::EntityWithForce::getMaxSpeed() const
{
    return maxSpeed;
}

void kmint::pigisland::EntityWithForce::setMaxSpeed(double maxSpeed)
{
    EntityWithForce::maxSpeed = maxSpeed;
}

double kmint::pigisland::EntityWithForce::getMaxForce() const
{
    return maxForce;
}

void kmint::pigisland::EntityWithForce::setMaxForce(double maxForce)
{
    EntityWithForce::maxForce = maxForce;
}

double kmint::pigisland::EntityWithForce::getMaxTurnRate() const
{
    return maxTurnRate;
}

void kmint::pigisland::EntityWithForce::setMaxTurnRate(double maxTurnRate)
{
    EntityWithForce::maxTurnRate = maxTurnRate;
}

const kmint::math::vector2d &kmint::pigisland::EntityWithForce::getAcceleration() const
{
    return acceleration;
}

void kmint::pigisland::EntityWithForce::setAcceleration(const kmint::math::vector2d &acceleration)
{
    EntityWithForce::acceleration = acceleration;
}

const kmint::math::vector2d &kmint::pigisland::EntityWithForce::getSide() const
{
    return side;
}

void kmint::pigisland::EntityWithForce::setSide(const kmint::math::vector2d &side)
{
    EntityWithForce::side = side;
}
