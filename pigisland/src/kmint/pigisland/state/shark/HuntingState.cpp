#include "./HuntingState.h"
#include "HuntingState.h"
#include "WanderingState.h"

#include <iostream>

bool kmint::pigisland::HuntingState::execute(kmint::pigisland::shark &shark)
{
    shark.resetTSinceMove();
    shark.move(shark.graph()[path->front()]);
    const_cast<map::map_graph &>(shark.graph())[path->front()].tag(kmint::graph::node_tag::normal);
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
    astar->tag(const_cast<map::map_graph &>(shark.graph()), *path);
}

void kmint::pigisland::HuntingState::exit(kmint::pigisland::shark &shark)
{
    std::cout << "Knabbel left hunting state." << std::endl;
    auto p = *path;
    astar->tag(const_cast<map::map_graph &>(shark.graph()), *path, kmint::graph::node_tag::normal);
}

kmint::pigisland::HuntingState::HuntingState(const map::map_node &target): astar(std::make_unique<Astar>()), destinationID(target.node_id())
{}
