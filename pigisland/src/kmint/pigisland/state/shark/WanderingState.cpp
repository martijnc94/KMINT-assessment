#include <iostream>
#include <kmint/pigisland/node_algorithm.hpp>
#include <kmint/pigisland/actor/pig.hpp>
#include "WanderingState.h"
#include "TiredState.h"
#include "HuntingState.h"

namespace kmint
{
    namespace pigisland
    {
        bool kmint::pigisland::WanderingState::execute(shark &sharkk)
        {
            sharkk.node(random_adjacent_node(sharkk.node()));
            sharkk.resetTSinceMove();

            for (auto i = sharkk.begin_perceived(); i != sharkk.end_perceived(); ++i) {
                auto &f = *i;
                if (auto p = dynamic_cast<pig *>(&f); p) {
                    sharkk.getStateMachine().changeState(std::make_unique<HuntingState>(find_closest_node(sharkk.graph(), p->location())));
                }
            }

            return true;
        }

        void kmint::pigisland::WanderingState::enter(kmint::pigisland::shark &shark)
        {
            std::cout << "Knabbel entered wandering state." << std::endl;
        }

        void kmint::pigisland::WanderingState::exit(kmint::pigisland::shark &shark)
        {
            std::cout << "Knabbel left wandering state." << std::endl;
        }

    }
}