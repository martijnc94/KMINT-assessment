#ifndef KMINT_ASESSMENT_SCAREDSTATE_H
#define KMINT_ASESSMENT_SCAREDSTATE_H

#include <kmint/pigisland/actor/shark.hpp>

namespace kmint
{
    namespace pigisland
    {
        class ScaredState : public State<shark>
        {
        public:
            bool execute(shark &entity) override;
            void enter(shark &entity) override;
            void exit(shark &entity) override;
        private:
            int counter = 0;
        };
    }
}

#endif //KMINT_ASESSMENT_SCAREDSTATE_H
