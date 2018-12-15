#include <kmint/pigisland/state/boat/BoatWanderingState.h>
#include "kmint/pigisland/actor/boat.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"
#include "boat.hpp"


namespace kmint
{
    namespace pigisland
    {
        boat::boat(kmint::map::map_graph &g) : play::map_bound_actor{g, find_random_mooring_place(g)},
                                               EntityWithState(*this),
                                               drawable_{*this, boat_image()},
                                               damage(0)/*, map_{&g}*/
        {
            stateMachine->changeState(std::make_unique<BoatWanderingState>());
        }

        void boat::act(delta_time dt)
        {
            t_since_move_ += dt;
            if (to_seconds(t_since_move_) >= waiting_time(node())) {
                stateMachine->update();
            }
        }

        void boat::setDamage(int amount)
        {
            if (amount < 0) {
                amount = 0;
            } else if (amount > 100) {
                amount = 100;
            }

            damage = amount;
        }

        void boat::resetTSinceMove()
        {
            t_since_move_ = from_seconds(0);
        }

        void boat::move(const map::map_node &position)
        {
            this->node(position);
        }

    } // namespace pigisland
} // namespace kmint
