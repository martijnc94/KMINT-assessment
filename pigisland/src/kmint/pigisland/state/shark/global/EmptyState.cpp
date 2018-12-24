#include <iostream>
#include "EmptyState.h"

bool kmint::pigisland::EmptyState::execute(kmint::pigisland::shark &entity)
{
    return false;
}

void kmint::pigisland::EmptyState::enter(kmint::pigisland::shark &entity)
{
    std::cout << "Knabbel entered empty (global) state." << std::endl;
}

void kmint::pigisland::EmptyState::exit(kmint::pigisland::shark &entity)
{
    std::cout << "Knabbel left empty (global) state." << std::endl;
}
