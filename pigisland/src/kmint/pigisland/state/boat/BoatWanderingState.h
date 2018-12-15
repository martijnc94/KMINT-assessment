#ifndef KMINT_ASESSMENT_WANDERINGSTATE_H
#define KMINT_ASESSMENT_WANDERINGSTATE_H

#include <kmint/pigisland/actor/boat.hpp>
#include <kmint/pigisland/algorithm/Astar.h>

namespace kmint
{
    namespace pigisland
    {
        class BoatWanderingState : public State<boat>
        {
        public:
            bool execute(boat &entity) override;
            void enter(boat &entity) override;
            void exit(boat &entity) override;
        };
    }
}


#endif //KMINT_ASESSMENT_WANDERINGSTATE_H
