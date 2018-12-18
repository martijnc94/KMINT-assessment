#ifndef KMINT_ASESSMENT_RANDOM_H
#define KMINT_ASESSMENT_RANDOM_H

#include <random>

std::default_random_engine &globalEngine()
{
    static std::default_random_engine u{};

    return u;
}

void randomize()
{
    static std::random_device rd{};
    globalEngine().seed(rd());
}

double pickRandomFloat(const double min, const double max)
{
    static std::uniform_real_distribution<double> d{min, max};

    return d(globalEngine());
}

#endif //KMINT_ASESSMENT_RANDOM_H
