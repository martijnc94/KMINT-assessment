#include <kmint/pigisland/state/boat/BoatWanderingState.h>
#include <kmint/pigisland/domain/Random.h>
#include "kmint/pigisland/actor/boat.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"
#include "boat.hpp"
#include <iostream>


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
            auto cornID = find_node_of_kind(graph(), '1').node_id();
            auto grassID = find_node_of_kind(graph(), '2').node_id();
            auto treeID = find_node_of_kind(graph(), '3').node_id();
            ports[cornID] = (std::make_unique<Port>(1, 30, 50));
            ports[grassID] = (std::make_unique<Port>(2, 20, 100));
            ports[treeID] = (std::make_unique<Port>(3, 50, 50));
            mooringChances[cornID] = 33;
            mooringChances[grassID] = 33;
            mooringChances[treeID] = 33;
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

        void boat::setMooringChange(int id, double chance)
        {
            mooringChances[id] = chance;
        }

        int boat::decideMooringChance() const
        {
            auto totalSum = std::accumulate(std::begin(mooringChances), std::end(mooringChances), 0, [](double value, const std::map<int, double>::value_type& p) {
                return value += p.second;
            });

            randomize();
            auto random = pickRandomInt(0, 99);
            double cumulativeProbability = 0.0;
            for (auto const &c : mooringChances) {
                cumulativeProbability += c.second;
                if (random <= cumulativeProbability) {
                    return c.first;
                }
            }

            return mooringChances.begin()->first;
        }

        void boat::resetMooringChances()
        {
            mooringChances.clear();
        }

        void boat::adjustMooringChance(int id, double amount)
        {
            auto newChance = (mooringChances[id] + amount) / 2;
            setMooringChange(id, newChance);
            for (auto& c : mooringChances) {
                if (c.first != id) {
                    setMooringChange(c.first, c.second - (newChance / 2));
                }
            }
        }

    } // namespace pigisland
} // namespace kmint
