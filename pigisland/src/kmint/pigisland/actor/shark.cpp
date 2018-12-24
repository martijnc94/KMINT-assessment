#include <kmint/pigisland/state/shark/WanderingState.h>
#include <kmint/pigisland/state/shark/global/NormalState.h>
#include "kmint/pigisland/actor/shark.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"
#include "shark.hpp"

namespace kmint
{
    namespace pigisland
    {
        shark::shark(kmint::map::map_graph &g, Farm &farm) : play::map_bound_actor{g, find_shark_resting_place(g)},
                                                                   EntityWithState(*this),
                                                                   energy(SHARKSTARTENERGY), farm(farm), drawable_{*this, shark_image()}, map_{&g},
                                                                   resting_place_(&node())
        {
            stateMachine->setGlobalState(std::make_unique<NormalState>());
            stateMachine->changeState(std::make_unique<WanderingState>());
        }

        void shark::act(delta_time dt)
        {
            play::map_bound_actor::act(dt);
            t_since_move_ += dt;
            if (to_seconds(t_since_move_) >= waiting_time(node())) {
                stateMachine->update();
            }
        }

        void shark::resetTSinceMove()
        {
            t_since_move_ = from_seconds(0);
        }

        int shark::getEnergy() const
        {
            return energy;
        }

        void shark::setEnergy(int energy)
        {
            shark::energy = energy;
        }

        void shark::move(const map::map_node &position)
        {
            this->node(position);
        }

        Farm &shark::getFarm() const
        {
            return farm;
        }

    } // namespace pigisland
} // namespace kmint
