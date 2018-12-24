#include <kmint/pigisland/domain/Random.h>
#include "Farm.h"

kmint::pigisland::Farm::Farm(play::stage &s): stage(s)
{}

std::vector<kmint::pigisland::pig *> kmint::pigisland::Farm::breed()
{
    // Generate chances for pig breeding.
    auto chances = generateBreedingChances();
    using mypair = std::pair<kmint::pigisland::pig *, double>;
    std::vector<mypair> sorted(std::begin(chances), std::end(chances));
    std::sort(std::begin(sorted), std::end(sorted), [](const mypair &a, const mypair &b) {
        return a.second > b.second;
    });

    std::vector<pig*> newPigs;
    randomize();
    auto random = pickRandomFloat(0, 1) / 100;
    pig* first;
    pig* second;
    for (int i = 0; i < 100; ++i) {
        first = choosePig(random, chances);
        random = pickRandomFloat(0, 1) / 100;
        second = choosePig(random, chances);
        while(first == second) {
            random = pickRandomFloat(0, 1) / 100;
            second = choosePig(random, chances);
        }

        auto newDna = std::make_unique<DNAString>(first->getGeneticAttributes() * second->getGeneticAttributes());

//        auto& pig = stage.build_actor<pigisland::pig>(math::vector2d(i * 10.0f, i * 6.0f), (*boat), (*shark), (*obstacles));
//        pig.setGeneticAttributes(newDna);
//        newPigs.push_back(&pig);
    }

    // Delete old generation of pigs.
    for (auto i = stage.begin(); i != stage.end(); ++i) {
        auto &f = *i;
        if (auto p = dynamic_cast<pig *>(&f); p) {
            stage.remove_actor(*i);
        }
    }

    return newPigs;
}

std::map<kmint::pigisland::pig *, double> kmint::pigisland::Farm::generateBreedingChances()
{
    auto chances = std::map<pig*, double>{};
    auto fitness = std::map<pig*, double>{};

    auto totalFitness = 0.0;
    // Calculate total and specific fitness for each pig.
    for (auto i = stage.begin(); i != stage.end(); ++i) {
        auto &f = *i;
        if (auto p = dynamic_cast<pig *>(&f); p) {
            auto curFitness = 0.0;
            curFitness += p->getFitness();
            if (p->isSaved()) {
                curFitness *= 1.5;
            }

            if (p->isEaten()) {
                curFitness *= 0.7;
            }

            fitness[p] = curFitness;
            totalFitness += curFitness;
        }
    }

    // Calculate breeding chances.
    for (auto& p : *pigs) {
        double chance = fitness[p] / totalFitness;
        chances[p] = chance;
    }

    return chances;
}

void kmint::pigisland::Farm::setPigPopulation(std::vector<kmint::pigisland::pig *> *p)
{
    pigs = p;
}

kmint::pigisland::pig *kmint::pigisland::Farm::choosePig(double random,
                                                         std::map<kmint::pigisland::pig *, double> &chances)
{
    for (auto& pig : chances) {
        if (pig.second <= random) {
            return pig.first;
        }
    }

    return chances.begin()->first;
}

void kmint::pigisland::Farm::setShark(kmint::pigisland::shark *shark)
{
    Farm::shark = shark;
}

void kmint::pigisland::Farm::setBoat(kmint::pigisland::boat *boat)
{
    Farm::boat = boat;
}

void kmint::pigisland::Farm::setObstacles(std::vector<kmint::pigisland::Obstacle> *obstacles)
{
    Farm::obstacles = obstacles;
}
