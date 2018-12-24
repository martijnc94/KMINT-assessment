#ifndef KMINT_ASESSMENT_HUNTING_H
#define KMINT_ASESSMENT_HUNTING_H

#include <kmint/pigisland/actor/shark.hpp>
#include <kmint/pigisland/state/State.h>
#include <kmint/pigisland/actor/pig.hpp>
#include <kmint/pigisland/algorithm/Astar.h>

namespace kmint
{
    namespace pigisland
    {
        class HuntingState : public State<shark>
        {
        public:
            explicit HuntingState(map::map_node const &target);
            bool execute(shark &shark) override;
            void enter(shark &shark) override;
            void exit(shark &shark) override;
        private:
            std::unique_ptr<Astar> astar;
            std::unique_ptr<std::vector<int>> path;
            int destinationID;
        };
    }
}

#endif //KMINT_ASESSMENT_HUNTING_H
