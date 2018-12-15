#ifndef KMINT_ASESSMENT_BOATDAMAGEDSTATE_H
#define KMINT_ASESSMENT_BOATDAMAGEDSTATE_H

#include <kmint/pigisland/actor/boat.hpp>
#include <kmint/pigisland/algorithm/Astar.h>

namespace kmint
{
    namespace pigisland
    {
        class BoatDamagedState : public State<boat>
        {
        public:
            BoatDamagedState();
            bool execute(boat &entity) override;
            void enter(boat &entity) override;
            void exit(boat &entity) override;

        private:
            std::unique_ptr<Astar> astar;
            size_t destinationID;
            std::unique_ptr<std::vector<int>> path;
        };
    }
}


#endif //KMINT_ASESSMENT_BOATDAMAGEDSTATE_H
