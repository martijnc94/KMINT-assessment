#ifndef KMINT_ASESSMENT_NORMALSTATE_H
#define KMINT_ASESSMENT_NORMALSTATE_H

#include <kmint/pigisland/actor/boat.hpp>

namespace kmint
{
    namespace pigisland
    {
        class InWaterState : public State<boat>
        {
        public:
            bool execute(boat &entity) override;
            void enter(boat &entity) override;
            void exit(boat &entity) override;
        };
    }
}


#endif //KMINT_ASESSMENT_NORMALSTATE_H
