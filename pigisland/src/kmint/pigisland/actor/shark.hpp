#ifndef KMINT_PIGISLAND_SHARK_HPP
#define KMINT_PIGISLAND_SHARK_HPP

#include <kmint/pigisland/state/StateMachine.h>
#include <kmint/pigisland/state/EntityWithState.h>
#include <kmint/pigisland/algorithm/Farm.h>
#include "kmint/map/map.hpp"
#include "kmint/play.hpp"
#include <kmint/pigisland/actor/shark.hpp>
#include "kmint/primitives.hpp"

namespace kmint
{
    namespace pigisland
    {
        static const int SHARKSTARTENERGY = 100;
        static const int SHARKSCAREDRANGE = 50;

        class shark : public play::map_bound_actor, public EntityWithState<shark>
        {
        public:
            explicit shark(kmint::map::map_graph &g, Farm &farm, boat &b);

            ui::drawable const &drawable() const override
            { return drawable_; }
            bool incorporeal() const override
            { return false; }
            scalar radius() const override
            { return 40.0; }
            void act(delta_time dt) override;
            void resetTSinceMove();
            void move(const map::map_node &position);
            scalar range_of_perception() const override { return 100.f;  }
            bool perceptive() const override { return true; }
            const map::map_node* getRestingPlace()
            { return resting_place_; };
            int getEnergy() const;
            void setEnergy(int energy);
            Farm &getFarm() const;
            boat &getBoat() const
            { return boatEntity; }
        private:
            int energy;
            Farm &farm;
            play::image_drawable drawable_;
            map::map_graph *map_;
            map::map_node const *resting_place_;
            delta_time t_since_move_{};
            boat &boatEntity;
        };

    } // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_SHARK_HPP */
