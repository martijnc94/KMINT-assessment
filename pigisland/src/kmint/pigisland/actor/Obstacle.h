#ifndef KMINT_ASESSMENT_OBSTACLE_H
#define KMINT_ASESSMENT_OBSTACLE_H

#include <kmint/play/static_actor.hpp>
#include <kmint/play/image_drawable.hpp>
#include <kmint/play.hpp>
#include <kmint/pigisland/force/EntityWithForce.h>

namespace kmint
{
    namespace pigisland
    {
        class Obstacle: public EntityWithForce
        {
        public:
            explicit Obstacle(math::vector2d location);
            const ui::drawable &drawable() const override;
            void act(delta_time dt) override;

        private:
            play::image_drawable drawable_;
        };
    }
}

#endif //KMINT_ASESSMENT_OBSTACLE_H
