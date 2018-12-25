#include <kmint/pigisland/state/shark/ScaredState.h>
#include <kmint/pigisland/state/shark/TiredState.h>
#include "NormalState.h"
#include "EmptyState.h"
#include <iostream>

namespace kmint
{
    namespace pigisland
    {

        bool NormalState::execute(shark &entity)
        {
            entity.setEnergy(entity.getEnergy() - 1);
            if (entity.getEnergy() <= 0) {
                entity.getStateMachine().changeState(std::make_unique<TiredState>());
                entity.getStateMachine().setGlobalState(std::make_unique<EmptyState>());
            }

            for (auto i = entity.begin_collision(); i != entity.end_collision(); ++i) {
                auto &f = *i;
                if (auto p = dynamic_cast<pig *>(&f); p) {
                    if (!p->isSaved()) {
                        p->setEaten(true);
                    }
                }
            }

            // Shark scared state demo code.
//            auto a = std::make_unique<Astar>();
//            auto path = a->perform(entity.graph(), entity.node(), entity.getBoat().node());
//            entity.move(entity.graph()[path.front()]);
//            path.erase(path.begin());

            auto distance = math::distance(entity.location(), entity.getBoat().location());
            if (distance <= SHARKSCAREDRANGE) {
                entity.getStateMachine().changeState(std::make_unique<ScaredState>());
                entity.getStateMachine().setGlobalState(std::make_unique<EmptyState>());
            }

            return true;
        }

        void NormalState::enter(shark &entity)
        {
            std::cout << "Knabbel entered normal (global) state." << std::endl;
        }

        void NormalState::exit(shark &entity)
        {
            std::cout << "Knabbel left normal (global) state." << std::endl;
        }
    }
}