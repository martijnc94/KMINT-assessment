#include "./HuntingState.h"
#include "HuntingState.h"
#include "WanderingState.h"

#include <iostream>

bool kmint::pigisland::HuntingState::execute(kmint::pigisland::shark &shark)
{
    shark.resetTSinceMove();
    shark.move(shark.graph()[path->front()]);
    path->erase(path->begin());

    if (shark.node().node_id() == destinationID) {
        shark.getStateMachine().changeState(std::make_unique<WanderingState>());
    }

    return true;
}

void kmint::pigisland::HuntingState::enter(kmint::pigisland::shark &shark)
{
    std::cout << "Knabbel entered hunting state." << std::endl;
    path = std::make_unique<std::vector<int>>(astar->perform(shark.graph(), shark.node(), shark.graph()[destinationID]));
}

void kmint::pigisland::HuntingState::exit(kmint::pigisland::shark &shark)
{
    std::cout << "Knabbel left hunting state." << std::endl;
}

kmint::pigisland::HuntingState::HuntingState(const map::map_node &target): astar(std::make_unique<Astar>()), destinationID(target.node_id())
{}
