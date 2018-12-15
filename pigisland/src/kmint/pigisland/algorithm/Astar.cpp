#include "Astar.h"

const double kmint::pigisland::Astar::heurestic(const kmint::map::map_node &a, const kmint::map::map_node &b) const
{
    return std::abs((a.location().x()) - (b.location().x()) + std::abs((a.location().y()) - (b.location().y()))) / 32;
}

std::vector<int> kmint::pigisland::Astar::perform(const map::map_graph &graph, const kmint::map::map_node &source,
                                                  const kmint::map::map_node &destination)
{
    std::map<int, double> fScore;
    std::map<int, double> gScore;
    std::map<int, int> cameFrom;
    std::vector<int> openList;
    std::vector<int> closedList;

    int visited = 0;

    for (auto i = 0; i < graph.num_nodes(); ++i) {
        openList.emplace_back(graph[i].node_id());
        gScore[graph[i].node_id()] =  std::numeric_limits<int>::max();
        fScore[graph[i].node_id()] = std::numeric_limits<int>::max();
    }

    cameFrom[source.node_id()] = source.node_id();
    gScore[source.node_id()] = 0;
    fScore[source.node_id()] = heurestic(source, destination);

    while(!openList.empty()) {
        auto smallest_id = get_lowest(graph, closedList, fScore);

        if (smallest_id == destination.node_id()) {
            return reconstruct_path(cameFrom, source.node_id(), smallest_id);
        }

        openList.erase(std::find(openList.begin(), openList.end(), smallest_id));
        closedList.emplace_back(smallest_id);
        visited++;

        for (auto neighbour = 0; neighbour < graph[smallest_id].num_edges(); ++neighbour) {
            auto other_id = graph[smallest_id][neighbour].to().node_id();
            if (std::find(closedList.begin(), closedList.end(), other_id) != closedList.end()) {
                continue;
            }

            auto tentative_gScore = gScore[smallest_id] + graph[smallest_id][neighbour].weight();

            if (std::find(openList.begin(), openList.end(), other_id) == openList.end()) {
                openList.emplace_back(other_id);
            } else if (tentative_gScore >= gScore[other_id]) {
                continue;
            }

            cameFrom[other_id] = smallest_id;
            gScore[other_id] = tentative_gScore;
            fScore[other_id] = gScore[other_id] + heurestic(graph[other_id], destination);
        }
    }
}
