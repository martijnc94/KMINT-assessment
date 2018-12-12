#include <iostream>
#include <kmint/pigisland/node_algorithm.hpp>
#include "WanderingState.h"

bool kmint::pigisland::WanderingState::execute(kmint::pigisland::shark &shark)
{
    shark.node(random_adjacent_node(shark.node()));
    shark.resetTSinceMove();

    return true;
}

void kmint::pigisland::WanderingState::enter(kmint::pigisland::shark &shark)
{
    std::cout << "Knabbel Entered wandering state." << std::endl;
}

void kmint::pigisland::WanderingState::exit(kmint::pigisland::shark &shark)
{
    std::cout << "Knabbel left wandering state." << std::endl;
}
