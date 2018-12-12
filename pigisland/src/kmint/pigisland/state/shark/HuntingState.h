#ifndef KMINT_ASESSMENT_HUNTING_H
#define KMINT_ASESSMENT_HUNTING_H

#include <kmint/pigisland/actor/shark.hpp>
#include <kmint/pigisland/state/State.h>

namespace kmint
{
    namespace pigisland
    {
        class HuntingState : public State<shark>
        {
        public:
            bool execute(shark &shark) override;
            void enter(shark &shark) override;
            void exit(shark &shark) override;
        };
    }
}

#endif //KMINT_ASESSMENT_HUNTING_H
