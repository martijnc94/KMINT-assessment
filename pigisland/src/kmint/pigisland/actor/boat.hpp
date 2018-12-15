#ifndef KMINT_PIGISLAND_BOAT_HPP
#define KMINT_PIGISLAND_BOAT_HPP

#include <kmint/pigisland/state/EntityWithState.h>
#include "kmint/map/map.hpp"
#include "kmint/play.hpp"
#include "kmint/primitives.hpp"
#include "kmint/pigisland/state/StateMachine.h"

namespace kmint
{
    namespace pigisland
    {

        class boat : public play::map_bound_actor, public EntityWithState<boat>
        {
        public:
            explicit boat(kmint::map::map_graph &g);

            ui::drawable const &drawable() const override
            { return drawable_; }

            bool incorporeal() const override
            { return false; }

            scalar radius() const override
            { return 16.0; }

            void act(delta_time dt) override;
            int getDamage() const { return damage; };
            void setDamage(int amount);
            void resetTSinceMove();
            void move(const map::map_node &position);
        private:
            play::image_drawable drawable_;
            //[[maybe_unused]] map::map_graph *map_;
            delta_time t_since_move_{};
            int damage;
        };

    } // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_BOAT_HPP */
