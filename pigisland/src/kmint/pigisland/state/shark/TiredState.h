#ifndef KMINT_ASESSMENT_TIREDSTATE_H
#define KMINT_ASESSMENT_TIREDSTATE_H

#include <kmint/pigisland/actor/shark.hpp>
#include <kmint/pigisland/algorithm/Astar.h>

namespace kmint
{
    namespace pigisland
    {
        class TiredState : public State<shark>
        {
        public:
            bool execute(shark &entity) override;
            void enter(shark &entity) override;
            void exit(shark &entity) override;
        private:
            std::unique_ptr<Astar> astar;
            std::unique_ptr<std::vector<int>> path;
            int destinationID;
        };
    }
}

#endif //KMINT_ASESSMENT_TIREDSTATE_H
