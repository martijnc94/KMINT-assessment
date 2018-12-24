#ifndef KMINT_ASESSMENT_EMPTYSTATE_H
#define KMINT_ASESSMENT_EMPTYSTATE_H

#include <kmint/pigisland/actor/shark.hpp>

namespace kmint
{
    namespace pigisland
    {
        class EmptyState : public State<shark>
        {
        public:
            bool execute(shark &entity) override;
            void enter(shark &entity) override;
            void exit(shark &entity) override;
        };
    }
}


#endif //KMINT_ASESSMENT_EMPTYSTATE_H
