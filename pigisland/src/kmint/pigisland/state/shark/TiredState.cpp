#include <iostream>
#include <kmint/pigisland/state/shark/global/NormalState.h>
#include "TiredState.h"
#include "WanderingState.h"

namespace kmint
{
    namespace pigisland
    {

        bool TiredState::execute(shark &entity)
        {
            entity.resetTSinceMove();
            entity.move(entity.graph()[path->front()]);
            path->erase(path->begin());

            if (entity.node().node_id() == destinationID) {
                // Initiate breeding.
                entity.getFarm().breed();

                // Reset the shark.
                entity.setEnergy(SHARKSTARTENERGY);
                entity.getStateMachine().changeState(std::make_unique<WanderingState>());
                entity.getStateMachine().setGlobalState(std::make_unique<NormalState>());
            }

            return true;
        }

        void TiredState::enter(shark &entity)
        {
            std::cout << "Knabbel entered tired state." << std::endl;

            astar = std::make_unique<Astar>();
            auto restingPlace = entity.getRestingPlace();
            destinationID = restingPlace->node_id();
            path = std::make_unique<std::vector<int>>(astar->perform(entity.graph(), entity.node(), *restingPlace));
        }

        void TiredState::exit(shark &entity)
        {
            std::cout << "Knabbel left tired state." << std::endl;
        }
    }
}