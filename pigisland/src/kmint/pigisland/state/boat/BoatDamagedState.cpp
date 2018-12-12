#include <iostream>
#include "BoatDamagedState.h"

bool kmint::pigisland::BoatDamagedState::execute(kmint::pigisland::boat &entity)
{
    return false;
}

void kmint::pigisland::BoatDamagedState::enter(kmint::pigisland::boat &entity)
{
    std::cout << "Porcus Victus entered damaged state." << std::endl;
}

void kmint::pigisland::BoatDamagedState::exit(kmint::pigisland::boat &entity)
{
    std::cout << "Porcus Victus left damaged state." << std::endl;
}
