#ifndef KMINT_ASESSMENT_DNASTRING_H
#define KMINT_ASESSMENT_DNASTRING_H

#include <memory>
#include <vector>

namespace kmint
{
    namespace pigisland
    {
        class DNAString
        {
        public:
            typedef std::vector<double> Chromosome;

            DNAString(double attractionToKnabbel, double attractionToPorcusVictus, double cohesion, double separation,
                      double alignment);
            DNAString();

            static std::unique_ptr<DNAString> createRandom();
            Chromosome getChromosome() const;
            void setChromosome(Chromosome const &chromosome);
            DNAString operator*(DNAString const &other) const;

            double getAttractionToKnabbel() const;
            void setAttractionToKnabbel(double attractionToKnabbel);
            double getAttractionToPorcusVictus() const;
            void setAttractionToPorcusVictus(double attractionToPorcusVictus);
            double getCohesion() const;
            void setCohesion(double cohesion);
            double getSeparation() const;
            void setSeparation(double separation);
            double getAlignment() const;
            void setAlignment(double alignment);
        private:
            double attractionToKnabbel;
            double attractionToPorcusVictus;
            double cohesion;
            double separation;
            double alignment;
        };
    }
}


#endif //KMINT_ASESSMENT_DNASTRING_H