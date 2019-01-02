#ifndef KMINT_ASESSMENT_STEERINGBEHAVIORS_H
#define KMINT_ASESSMENT_STEERINGBEHAVIORS_H

#include <kmint/play/free_roaming_actor.hpp>
#include <kmint/pigisland/actor/Obstacle.h>

enum Deceleration{slow = 3, normal = 2, fast = 1};

namespace kmint
{
    namespace pigisland
    {
        class pig;
        class SteeringBehaviors
        {
        public:
            explicit SteeringBehaviors(pig &actor, std::vector<Obstacle> &obstacles);
            math::vector2d calculate();
            void enforceNonPenetrationConstraint();
        private:
            pig &actor;
            std::vector<Obstacle> &obstacles;
            std::vector<math::vector2d> feelers;

            math::vector2d seek(math::vector2d &targetPos);
            math::vector2d arrive(math::vector2d &target, Deceleration deceleration);
            math::vector2d cohesion();
            math::vector2d separation();
            math::vector2d alignment();
            math::vector2d obstacleAvoidance(const Obstacle& o);
        };
    }
}


#endif //KMINT_ASESSMENT_STEERINGBEHAVIORS_H
