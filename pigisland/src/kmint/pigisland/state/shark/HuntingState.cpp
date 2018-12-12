#include "./HuntingState.h"
#include <iostream>

bool kmint::pigisland::HuntingState::execute(kmint::pigisland::shark &shark)
{
    return true;
}

void kmint::pigisland::HuntingState::enter(kmint::pigisland::shark &shark)
{
    std::cout << "Knabbel entered hunting state." << std::endl;
}

void kmint::pigisland::HuntingState::exit(kmint::pigisland::shark &shark)
{
    std::cout << "Knabbel left hunting state." << std::endl;
}
