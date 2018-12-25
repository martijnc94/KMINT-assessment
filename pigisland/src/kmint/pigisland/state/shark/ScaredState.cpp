#include <iostream>
#include <kmint/pigisland/state/shark/global/NormalState.h>
#include <kmint/pigisland/node_algorithm.hpp>
#include "ScaredState.h"
#include "WanderingState.h"

namespace kmint
{
    namespace pigisland
    {

        bool ScaredState::execute(shark &entity)
        {
            ++counter;
            entity.node(random_adjacent_node(entity.node()));

            if (counter >= 10) {
                entity.getStateMachine().changeState(std::make_unique<WanderingState>());
                entity.getStateMachine().setGlobalState(std::make_unique<NormalState>());
            }

            return false;
        }

        void ScaredState::enter(shark &entity)
        {
            std::cout << "Knabbel entered scared state." << std::endl;
        }

        void ScaredState::exit(shark &entity)
        {
            std::cout << "Knabbel left scared state." << std::endl;
        }
    }
}