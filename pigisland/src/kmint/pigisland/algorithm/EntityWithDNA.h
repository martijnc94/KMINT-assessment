#ifndef KMINT_ASESSMENT_ENTITYWITHDNA_H
#define KMINT_ASESSMENT_ENTITYWITHDNA_H


#include <memory>
#include <kmint/pigisland/domain/DNAString.h>

namespace kmint
{
    namespace pigisland
    {
        class EntityWithDNA
        {
        public:
            EntityWithDNA();
            void setGeneticAttributes(std::unique_ptr<DNAString> &gA);
            DNAString &getGeneticAttributes() const;
        protected:
            std::unique_ptr<DNAString> geneticAttributes;
        };
    }
}

#endif //KMINT_ASESSMENT_ENTITYWITHDNA_H
