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
        private:
            std::map<pig *, double> generateBreedingChances();
            pig* choosePig(double random, std::map<kmint::pigisland::pig *, double> &chances);
            play::stage& stage;
        };
    }
}

#endif //KMINT_ASESSMENT_FARM_H
