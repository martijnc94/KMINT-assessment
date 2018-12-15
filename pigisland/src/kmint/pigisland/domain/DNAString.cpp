#include "DNAString.h"

DNAString::DNAString(double attractionToKnabbel, double attractionToPorcusVictus, double cohesion, double separation,
                     double alignment) : attractionToKnabbel(attractionToKnabbel),
                                         attractionToPorcusVictus(attractionToPorcusVictus), cohesion(cohesion),
                                         separation(separation), alignment(alignment)
{}

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
