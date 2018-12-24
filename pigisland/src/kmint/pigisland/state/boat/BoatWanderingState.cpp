#include <iostream>
#include <kmint/pigisland/node_algorithm.hpp>
#include "BoatWanderingState.h"
#include "BoatDamagedState.h"

bool kmint::pigisland::BoatWanderingState::execute(kmint::pigisland::boat &entity)
{
    entity.node(random_adjacent_node(entity.node()));
    entity.resetTSinceMove();
    entity.setDamage(entity.getDamage() + 1);

    if (entity.getDamage() >= BOATDAMAGERESISTANCE ) {
        entity.getStateMachine().changeState(std::make_unique<BoatDamagedState>());
    }

    return true;
}

void kmint::pigisland::BoatWanderingState::exit(kmint::pigisland::boat &entity)
{
    std::cout << "Porcus Victus left wandering state." << std::endl;
}

void kmint::pigisland::BoatWanderingState::enter(kmint::pigisland::boat &entity)
{
    std::cout << "Porcus Victus entered wandering state." << std::endl;
}

