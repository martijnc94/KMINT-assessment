#ifndef KMINT_ASESSMENT_FARM_H
#define KMINT_ASESSMENT_FARM_H

#include <vector>
#include <kmint/pigisland/actor/pig.hpp>

namespace kmint
{
    namespace pigisland
    {
        class Farm
        {
        public:
            explicit Farm(play::stage &s);
            std::vector<pig *> breed();
            void setPigPopulation(std::vector<pig*>* p);
            void setShark(pigisland::shark *shark);
            void setBoat(pigisland::boat *boat);
            void setObstacles(std::vector<Obstacle> *obstacles);
        private:
            std::map<pig *, double> generateBreedingChances();
            pig* choosePig(double random, std::map<kmint::pigisland::pig *, double> &chances);
            std::vector<pig*> *pigs;
            play::stage& stage;
            shark* shark;
            boat* boat;
            std::vector<Obstacle>* obstacles;
        };
    }
}

#endif //KMINT_ASESSMENT_FARM_H
