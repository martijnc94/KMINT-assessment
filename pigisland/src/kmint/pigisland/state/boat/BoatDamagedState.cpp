#include <iostream>
#include <kmint/pigisland/node_algorithm.hpp>
#include "BoatDamagedState.h"
#include "BoatWanderingState.h"
#include <kmint/pigisland/domain/Random.h>

kmint::pigisland::BoatDamagedState::BoatDamagedState(): astar(std::make_unique<Astar>())
{

}

bool kmint::pigisland::BoatDamagedState::execute(kmint::pigisland::boat &entity)
{
    entity.resetTSinceMove();
    entity.move(entity.graph()[path->front()]);
    path->erase(path->begin());

    if (entity.node().node_id() == destinationID) {
        randomize();
        // Retrieve random repair amount.
        auto amountRepaired = pickRandomInt(entity.getPort(destinationID).getMinRecovery(), entity.getPort(destinationID).getMaxRecovery());
        entity.setDamage(entity.getDamage() - amountRepaired);
        std::cout << "Porcus his boat got repaired  for " << amountRepaired << std::endl;

        // Adjust mooring chances.
        entity.adjustMooringChance(static_cast<int>(destinationID), amountRepaired);

        entity.getStateMachine().changeState(std::make_unique<BoatWanderingState>());
    }

    return true;
}

void kmint::pigisland::BoatDamagedState::enter(kmint::pigisland::boat &entity)
{
    std::cout << "Porcus Victus entered damaged state." << std::endl;

    auto cornID = find_node_of_kind(entity.graph(), '1').node_id();
    auto grassID = find_node_of_kind(entity.graph(), '2').node_id();
    auto treeID = find_node_of_kind(entity.graph(), '3').node_id();

    destinationID = entity.decideMooringChance();
    path = std::make_unique<std::vector<int>>(astar->perform(entity.graph(), entity.node(), entity.graph()[destinationID]));
}

void kmint::pigisland::BoatDamagedState::exit(kmint::pigisland::boat &entity)
{
    std::cout << "Porcus Victus left damaged state." << std::endl;
}

