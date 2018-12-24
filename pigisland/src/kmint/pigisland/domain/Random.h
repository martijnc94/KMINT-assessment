#ifndef KMINT_ASESSMENT_RANDOM_H
#define KMINT_ASESSMENT_RANDOM_H

#include <random>

namespace kmint
{
    namespace pigisland
    {

        static std::default_random_engine &globalEngine()
        {
            static std::default_random_engine u{};

            return u;
        }

        static void randomize()
        {
            static std::random_device rd{};
            globalEngine().seed(rd());
        }

        static double pickRandomFloat(const double min, const double max)
        {
            static std::uniform_real_distribution<double> d{min, max};

            return d(globalEngine());
        }

        static int pickRandomInt(int min, int max)
        {
            static std::uniform_int_distribution<> d{min, max};

            return d(globalEngine());
        }
    }
}

#endif //KMINT_ASESSMENT_RANDOM_H
