#ifndef KMINT_ASESSMENT_BOATDAMAGEDSTATE_H
#define KMINT_ASESSMENT_BOATDAMAGEDSTATE_H

#include <kmint/pigisland/actor/boat.hpp>

namespace kmint
{
    namespace pigisland
    {
        class BoatDamagedState : State<boat>
        {
            bool execute(boat &entity) override;
            void enter(boat &entity) override;
            void exit(boat &entity) override;
        };
    }
}


#endif //KMINT_ASESSMENT_BOATDAMAGEDSTATE_H
