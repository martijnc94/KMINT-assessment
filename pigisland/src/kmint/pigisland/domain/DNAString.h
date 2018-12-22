#ifndef KMINT_ASESSMENT_DNASTRING_H
#define KMINT_ASESSMENT_DNASTRING_H

#include <memory>

namespace kmint
{
    namespace pigisland
    {
        class DNAString
        {
        public:
            DNAString(double attractionToKnabbel, double attractionToPorcusVictus, double cohesion, double separation,
                      double alignment);

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
            static std::unique_ptr<DNAString> createRandom();
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