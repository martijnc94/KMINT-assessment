#include <kmint/pigisland/resources.hpp>
#include <kmint/pigisland/force/EntityWithForce.h>
#include "Obstacle.h"

namespace kmint
{
    namespace pigisland
    {
        Obstacle::Obstacle(math::vector2d location): EntityWithForce{location}, drawable_{*this, pig_image()}
        {}

        const ui::drawable &Obstacle::drawable() const
        {
            return drawable_;
        }

        void Obstacle::act(delta_time dt)
        {
            free_roaming_actor::act(dt);
        }
    }
}
