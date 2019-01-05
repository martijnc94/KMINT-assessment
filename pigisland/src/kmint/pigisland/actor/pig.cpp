#include "kmint/pigisland/actor/pig.hpp"
#include "kmint/math/angle.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"
#include "pig.hpp"
#include "kmint/pigisland/math.h"
#include "shark.hpp"

#include <cmath>

namespace kmint
{
    namespace pigisland
    {

        namespace
        {

            math::vector2d random_vector()
            {
                auto x = random_scalar(100, 924);
                auto y = random_scalar(50, 728);
                return {x, y};
            }
        } // namespace

        pig::pig(math::vector2d location, boat &b, shark &s, std::vector<Obstacle *> &obstacles)
                : EntityWithForce{random_vector()},
                  EntityWithDNA(),
                  boatActor(b),
                  sharkActor(s), drawable_{*this, pig_image()},
                  steeringBehaviors(std::make_unique<SteeringBehaviors>(*this, obstacles)),
                  eaten(false),
                  saved(false),
                  fitness(BASEFITNESS)
        {}


        void pig::act(delta_time dt)
        {
            free_roaming_actor::act(dt);

            auto steeringForce = steeringBehaviors->calculate();
            acceleration = steeringForce / mass;
            setVelocity(dt);
            if (vectorLength(velocity) > 0.00000001) {
                heading = vectorNormalize(velocity);
                side = vectorPerp(heading);
                location(location() + velocity);
                wrapAround(*this);
                steeringBehaviors->enforceNonPenetrationConstraint();
                setFitness(getFitness() - 1);
            }
        }

        pig::pig(math::vector2d location, boat &b, shark &s, std::unique_ptr<DNAString> dna,
                 std::vector<Obstacle *> &obstacles)
                : EntityWithForce{
                random_vector()}, boatActor(b), sharkActor(s), drawable_{*this, pig_image()},
                steeringBehaviors(
                std::make_unique<SteeringBehaviors>(*this, obstacles)),
                eaten(false),
                saved(false),
                fitness(0)
        {}

        boat &pig::getBoat() const
        {
            return boatActor;
        }

        shark &pig::getShark() const
        {
            return sharkActor;
        }

        bool pig::isSaved() const
        {
            return saved;
        }

        void pig::setSaved(bool saved)
        {
            pig::saved = saved;
        }

        bool pig::isEaten() const
        {
            return eaten;
        }

        int pig::getFitness() const
        {
            return fitness;
        }

        void pig::setFitness(int fitness)
        {
            if (!eaten && !saved) {
                pig::fitness = fitness;
            }
        }
    } // namespace pigisland

} // namespace kmint
