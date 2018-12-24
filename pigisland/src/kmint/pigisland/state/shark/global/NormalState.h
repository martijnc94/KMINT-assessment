#ifndef KMINT_ASESSMENT_NORMALSTATE_H
#define KMINT_ASESSMENT_NORMALSTATE_H

#include <kmint/pigisland/actor/shark.hpp>

namespace kmint
{
    namespace pigisland
    {

        class NormalState : public State<shark>
        {
        public:
            bool execute(shark &entity) override;
            void enter(shark &entity) override;
            void exit(shark &entity) override;
        };
    }
}


#endif //KMINT_ASESSMENT_NORMALSTATE_H
