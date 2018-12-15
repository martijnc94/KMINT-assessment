#include <iostream>
#include <kmint/pigisland/node_algorithm.hpp>
#include "BoatDamagedState.h"
#include "BoatWanderingState.h"

kmint::pigisland::BoatDamagedState::BoatDamagedState(): astar(std::make_unique<Astar>())
{

}

bool kmint::pigisland::BoatDamagedState::execute(kmint::pigisland::boat &entity)
{
    entity.resetTSinceMove();
    entity.move(entity.graph()[path->front()]);
    path->erase(path->begin());

    if (entity.node().node_id() == destinationID) {
        entity.setDamage(0);
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
    auto cornPath = astar->perform(entity.graph(), entity.node(), entity.graph()[cornID]);
    auto grassPath = astar->perform(entity.graph(), entity.node(), entity.graph()[grassID]);
    auto treePath = astar->perform(entity.graph(), entity.node(), entity.graph()[treeID]);

    auto min = std::min(treePath.size(), std::min(cornPath.size(), grassPath.size()));

    if (min == cornPath.size()) {
        destinationID = cornID;
        path = std::make_unique<std::vector<int>>(cornPath);
    } else if (min == grassPath.size()) {
        destinationID = grassID;
        path = std::make_unique<std::vector<int>>(grassPath);
    } else if (min == treePath.size()) {
        destinationID = treeID;
        path = std::make_unique<std::vector<int>>(treePath);
    }
}

void kmint::pigisland::BoatDamagedState::exit(kmint::pigisland::boat &entity)
{
    std::cout << "Porcus Victus left damaged state." << std::endl;
}

