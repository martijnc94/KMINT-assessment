#ifndef KMINT_ASESSMENT_ENTITYWITHFORCE_H
#define KMINT_ASESSMENT_ENTITYWITHFORCE_H
#include <kmint/play/free_roaming_actor.hpp>
#include <kmint/pigisland/math.h>

namespace kmint
{
    namespace pigisland
    {
        class EntityWithForce : public play::free_roaming_actor
        {
        public:
            explicit EntityWithForce(math::vector2d location);

            double getMass() const;
            void setMass(double mass);
            const math::vector2d &getVelocity() const;
            void setVelocity(const delta_time dt);
            const math::vector2d &getHeading() const;
            void setHeading(const math::vector2d &heading);
            double getMaxSpeed() const;
            void setMaxSpeed(double maxSpeed);
            double getMaxForce() const;
            void setMaxForce(double maxForce);
            double getMaxTurnRate() const;
            void setMaxTurnRate(double maxTurnRate);
            const math::vector2d &getAcceleration() const;
            void setAcceleration(const math::vector2d &acceleration);
            const math::vector2d &getSide() const;
            void setSide(const math::vector2d &side);
            void setLocation(const math::vector2d &loc)
            { location(loc); }
            double getSpeed() const
            { return vectorLength(getVelocity()); }
        protected:
            double mass{1};
            math::vector2d velocity;
            math::vector2d acceleration;
            math::vector2d heading;
            math::vector2d side;
            double maxSpeed{40};
            double maxForce{1};
            double maxTurnRate{1};
        };
    }
}


#endif //KMINT_ASESSMENT_ENTITYWITHFORCE_H
