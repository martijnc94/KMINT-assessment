#include <memory>
#include "DNAString.h"
#include "Random.h"

namespace kmint
{
    namespace pigisland
    {
        DNAString::DNAString(double attractionToKnabbel, double attractionToPorcusVictus, double cohesion,
                             double separation, double alignment) : attractionToKnabbel(attractionToKnabbel),
                                                                    attractionToPorcusVictus(attractionToPorcusVictus),
                                                                    cohesion(cohesion), separation(separation),
                                                                    alignment(alignment)
        {}


        DNAString::DNAString() : attractionToKnabbel(0), attractionToPorcusVictus(0), cohesion(0), separation(0), alignment(0)
        {

        }


        double DNAString::getAttractionToKnabbel() const
        {
            return attractionToKnabbel;
        }

        void DNAString::setAttractionToKnabbel(double attractionToKnabbel)
        {
            DNAString::attractionToKnabbel = attractionToKnabbel;
        }

        double DNAString::getAttractionToPorcusVictus() const
        {
            return attractionToPorcusVictus;
        }

        void DNAString::setAttractionToPorcusVictus(double attractionToPorcusVictus)
        {
            DNAString::attractionToPorcusVictus = attractionToPorcusVictus;
        }

        double DNAString::getCohesion() const
        {
            return cohesion;
        }

        void DNAString::setCohesion(double cohesion)
        {
            DNAString::cohesion = cohesion;
        }

        double DNAString::getSeparation() const
        {
            return separation;
        }

        void DNAString::setSeparation(double separation)
        {
            DNAString::separation = separation;
        }

        double DNAString::getAlignment() const
        {
            return alignment;
        }

        void DNAString::setAlignment(double alignment)
        {
            DNAString::alignment = alignment;
        }

        std::unique_ptr<DNAString> DNAString::createRandom()
        {
            return std::make_unique<DNAString>(
                    pickRandomFloat(-1.0, 1.0),
                    pickRandomFloat(-1.0, 1.0),
                    pickRandomFloat(0, 1.0),
                    pickRandomFloat(0, 1.0),
                    pickRandomFloat(0, 1.0)
            );
        }

        DNAString::Chromosome DNAString::getChromosome() const
        {
            auto dString = Chromosome{};
            dString.emplace_back(getAttractionToKnabbel());
            dString.emplace_back(getAttractionToPorcusVictus());
            dString.emplace_back(getCohesion());
            dString.emplace_back(getSeparation());
            dString.emplace_back(getAlignment());

            return dString;
        }

        void DNAString::setChromosome(const DNAString::Chromosome &chromosome)
        {
            setAttractionToKnabbel(chromosome[0]);
            setAttractionToPorcusVictus(chromosome[1]);
            setCohesion(chromosome[2]);
            setSeparation(chromosome[3]);
            setAlignment(chromosome[4]);
        }

        DNAString DNAString::operator*(DNAString const &other) const
        {
            randomize();
            auto newDNAString = DNAString{};
            auto newChromosome = Chromosome{};
            auto chro1 = getChromosome();
            auto chro2 = other.getChromosome();
            newChromosome.resize(chro1.size());

            auto split = pickRandomInt(1, static_cast<int>(chro1.size() - 1));
            for (auto i = 0; i < split; ++i) {
                newChromosome[i] = chro1[i];
            }
            for (auto i = split; i < chro1.size(); ++i) {
                newChromosome[i] = chro2[i];
            }

            randomize();
            auto r = pickRandomInt(0, 99);
            auto toMutate = (pickRandomInt(0, 99) < 5);
            if (toMutate) {
                auto mutateIndex = pickRandomInt(0, static_cast<int>(chro1.size()) - 1);
                auto mutateAmount = pickRandomFloat(0, 1);
                newChromosome[mutateIndex] = mutateAmount;
            }

            newDNAString.setChromosome(newChromosome);

            return newDNAString;
        }
    }
}