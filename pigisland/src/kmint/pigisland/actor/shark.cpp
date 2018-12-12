#include <kmint/pigisland/state/shark/WanderingState.h>
#include "kmint/pigisland/actor/shark.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"
#include "shark.hpp"


namespace kmint
{
    namespace pigisland
    {

        shark::shark(kmint::map::map_graph &g) : play::map_bound_actor{g, find_shark_resting_place(g)},
                                                 EntityWithState(*this), drawable_{*this, shark_image()}, map_{&g},
                                                 resting_place_(&node())
        {
            stateMachine->changeState(std::make_unique<WanderingState>());
        }

        void shark::act(delta_time dt)
        {
            t_since_move_ += dt;
            if (to_seconds(t_since_move_) >= waiting_time(node())) {
                stateMachine->update();
            }
        }

        void shark::resetTSinceMove()
        {
            t_since_move_ = from_seconds(0);
        }

    } // namespace pigisland
} // namespace kmint
