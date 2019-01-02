#include "EntityWithDNA.h"

namespace kmint
{
    namespace pigisland
    {

        void EntityWithDNA::setGeneticAttributes(std::unique_ptr<DNAString> &gA)
        {
            geneticAttributes = std::move(gA);
        }

        DNAString &EntityWithDNA::getGeneticAttributes() const
        {
            return *geneticAttributes;
        }

        EntityWithDNA::EntityWithDNA() : geneticAttributes(DNAString::createRandom())
        {}
    }
}