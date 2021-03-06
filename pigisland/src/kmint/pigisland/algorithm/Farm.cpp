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

    // Generate new DNA strings from existing pig population.
    auto counter = 0;
    std::vector<std::unique_ptr<DNAString>> dnaList;
    for (auto p = stage.begin(); p != stage.end(); ++p) {
        auto &f = *p;
        if (auto c = dynamic_cast<pig *>(&f); c) {
            first = choosePig(random, chances);
            random = pickRandomFloat(0, 1) / 100;
            second = choosePig(random, chances);
            while(first == second) {
                random = pickRandomFloat(0, 1) / 100;
                second = choosePig(random, chances);
            }

            dnaList.emplace_back(std::make_unique<DNAString>(first->getGeneticAttributes() * second->getGeneticAttributes()));

            ++counter;
        }
    }

    // Make new pig population from the newly chosen DNA strings.
    counter = 0;
    for (auto p = stage.begin(); p != stage.end(); ++p) {
        auto &f = *p;
        if (auto c = dynamic_cast<pig *>(&f); c) {
            auto newLoc = random_vector();
            c->setLocation(newLoc);
            c->setGeneticAttributes(dnaList[counter]);

            c->setFitness(BASEFITNESS);
            c->setEaten(false);
            c->setSaved(false);

            ++counter;
        }
    }

    return newPigs;
}

std::map<kmint::pigisland::pig *, double> kmint::pigisland::Farm::generateBreedingChances()
{
    // Holds the chance the pig will be chosen.
    auto chances = std::map<pig*, double>{};
    // Holds the final calculated fitness score.
    auto fitness = std::map<pig*, double>{};

    auto totalFitness = 0.0;
    // Calculate total and specific fitness for each pig.
    for (auto i = stage.begin(); i != stage.end(); ++i) {
        auto &f = *i;
        if (auto p = dynamic_cast<pig *>(&f); p) {
            auto curFitness = 0.0;
            curFitness += p->getFitness();
            if (p->isSaved()) {
                curFitness *= 10.5;
            }

            if (p->isEaten()) {
                curFitness *= 0.7;
            }

            fitness[p] = curFitness;
            totalFitness += curFitness;
        }
    }

    // Calculate breeding chances.
    for (auto p = stage.begin(); p != stage.end(); ++p) {
        auto &f = *p;
        if (auto c = dynamic_cast<pig *>(&f); c) {
            double chance = fitness[c] / totalFitness;
            chances[c] = chance;
        }
    }

    return chances;
}

kmint::pigisland::pig *kmint::pigisland::Farm::choosePig(double random,
                                                         std::map<kmint::pigisland::pig *, double> &chances)
{
    // Choose a pig, based on the earlier calculated chances.
    for (auto& pig : chances) {
        if (pig.second <= random) {
            return pig.first;
        }
    }

    return chances.begin()->first;
}
