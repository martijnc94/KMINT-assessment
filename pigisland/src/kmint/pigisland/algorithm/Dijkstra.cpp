#include "Dijkstra.h"
#include <iostream>

std::vector<int>
kmint::pigisland::Dijkstra::perform(const kmint::map::map_graph &graph, const kmint::map::map_node &source,
                                    const kmint::map::map_node &destination)
{
    // Holds the distance to the destination.
    std::map<int, double> score;
    // Holds the parents from the nodes, making the shortest path.
    std::map<int, int> cameFrom;
    // Holds al nodes which are not visited.
    std::vector<int> openList;
    // Holds all nodes which are visited.
    std::vector<int> closedList;

    int visited = 0;

    // Initialize all nodes in graph.
    for (auto i = 0; i < graph.num_nodes(); ++i) {
        openList.emplace_back(graph[i].node_id());
        score[graph[i].node_id()] = std::numeric_limits<int>::max();
    }

    // Set the source node, as this is always the starting point.
    cameFrom[source.node_id()] = source.node_id();
    score[source.node_id()] = 0;

    while (!openList.empty()) {
        auto smallest_id = get_lowest(graph, closedList, score);

        if (smallest_id == destination.node_id()) {
            std::cout << "Dijkstra visited " << visited << " nodes." << std::endl;

            return reconstruct_path(cameFrom, source.node_id(), smallest_id);
        }

        openList.erase(std::find(openList.begin(), openList.end(), smallest_id));
        closedList.emplace_back(smallest_id);
        ++visited;

        for (auto neighbour = 0; neighbour < graph[smallest_id].num_edges(); ++neighbour) {
            auto other_id = graph[smallest_id][neighbour].to().node_id();
            if (std::find(closedList.begin(), closedList.end(), other_id) != closedList.end()) {
                continue;
            }

            auto tentative_score = score[smallest_id] + graph[smallest_id][neighbour].weight();

            if (std::find(openList.begin(), openList.end(), other_id) == openList.end()) {
                openList.emplace_back(other_id);
            } else if (tentative_score >= score[other_id]) {
                continue;
            }

            cameFrom[other_id] = smallest_id;
            score[other_id] = tentative_score;
        }
    }
}
