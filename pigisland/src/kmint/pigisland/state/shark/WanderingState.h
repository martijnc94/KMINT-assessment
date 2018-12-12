#ifndef KMINT_ASESSMENT_WANDERINGSTATE_H
#define KMINT_ASESSMENT_WANDERINGSTATE_H

#include <kmint/pigisland/actor/shark.hpp>
#include <kmint/pigisland/state/State.h>

namespace kmint
{
namespace pigisland
{
    class WanderingState : public State<shark>
    {
    public:
        bool execute(shark &shark) override;
        void enter(shark &shark) override;
        void exit(shark &shark) override;
    };
}
}


#endif //KMINT_ASESSMENT_WANDERINGSTATE_H
