#include <iostream>
#include <kmint/pigisland/actor/pig.hpp>
#include "InWaterState.h"

namespace kmint
{
    namespace pigisland
    {
        bool InWaterState::execute(kmint::pigisland::boat &entity)
        {
            for (auto i = entity.begin_collision(); i != entity.end_collision(); ++i) {
                auto &f = *i;
                if (auto p = dynamic_cast<pig *>(&f); p) {
                    if (!p->isEaten()) {
                        p->setSaved(true);
                    }
                }
            }

            return true;
        }

        void InWaterState::enter(kmint::pigisland::boat &entity)
        {
            std::cout << "Porcus Victus entered normal (global) state." << std::endl;
        }

        void InWaterState::exit(kmint::pigisland::boat &entity)
        {
            std::cout << "Porcus Victus left normal (global) state." << std::endl;
        }

    }
}