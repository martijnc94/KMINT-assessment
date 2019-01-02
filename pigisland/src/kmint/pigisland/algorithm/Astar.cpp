#include "Astar.h"

const double kmint::pigisland::Astar::heuristic(const kmint::map::map_node &a, const kmint::map::map_node &b) const
{
    // Calculate the heuristic for the given source and destination node as the crows fly and divide this by the grid size.
    return std::abs((a.location().x()) - (b.location().x()) + std::abs((a.location().y()) - (b.location().y()))) / 32;
}

std::vector<int> kmint::pigisland::Astar::perform(const map::map_graph &graph, const kmint::map::map_node &source,
                                                  const kmint::map::map_node &destination)
{
    // Holds the distance to the destination.
    std::map<int, double> score;
    // Holds the distance to the destination with heuristic.
    std::map<int, double> hScore;
    // Holds the parents from the nodes, making the shortest path.
    std::map<int, int> cameFrom;
    // Holds al nodes which are not visited.
    std::vector<int> openList;
    // Holds all nodes which are visited.
    std::vector<int> closedList;

    // Initialize all nodes in graph.
    for (auto i = 0; i < graph.num_nodes(); ++i) {
        openList.emplace_back(graph[i].node_id());
        hScore[graph[i].node_id()] =  std::numeric_limits<int>::max();
        score[graph[i].node_id()] = std::numeric_limits<int>::max();
    }

    // Set the source node, as this is always the starting point.
    cameFrom[source.node_id()] = source.node_id();
    hScore[source.node_id()] = 0;
    score[source.node_id()] = heuristic(source, destination);

    while(!openList.empty()) {
        auto smallest_id = get_lowest(graph, closedList, score);

        // Check if the destination is reached.
        if (smallest_id == destination.node_id()) {
            return reconstruct_path(cameFrom, source.node_id(), smallest_id);
        }

        openList.erase(std::find(openList.begin(), openList.end(), smallest_id));
        closedList.emplace_back(smallest_id);

        // Update the scores with and without the heuristic.
        for (auto neighbour = 0; neighbour < graph[smallest_id].num_edges(); ++neighbour) {
            auto other_id = graph[smallest_id][neighbour].to().node_id();
            if (std::find(closedList.begin(), closedList.end(), other_id) != closedList.end()) {
                continue;
            }

            auto tentativeScore = hScore[smallest_id] + graph[smallest_id][neighbour].weight();

            if (std::find(openList.begin(), openList.end(), other_id) == openList.end()) {
                openList.emplace_back(other_id);
            } else if (tentativeScore >= hScore[other_id]) {
                continue;
            }

            // Update the parents list and scores.
            cameFrom[other_id] = smallest_id;
            hScore[other_id] = tentativeScore;
            score[other_id] = hScore[other_id] + heuristic(graph[other_id], destination);
        }
    }
}
