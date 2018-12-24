#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/random.hpp"
#include <algorithm>
#include <map>
#include <kmint/play/actor.hpp>

namespace kmint {
namespace pigisland {

map::map_node const &random_adjacent_node(map::map_node const &node) {
  int r = random_int(0, node.num_edges());
  return node[r].to();
}

map::map_node const &find_node_of_kind(map::map_graph const &graph, char kind) {
  auto i = std::find_if(graph.begin(), graph.end(), [kind](auto const &node) {
    return node.node_info().kind == kind;
  });
  return *i;
}

map::map_node const &find_random_mooring_place(map::map_graph const &graph) {
  return find_node_of_kind(graph, '1' + random_int(0, 3));
}

map::map_node const &find_shark_resting_place(map::map_graph const &graph) {
  return find_node_of_kind(graph, 'K');
}

map::map_node const &find_closest_node(map::map_graph const &graph, math::vector2d const &a) {
  std::map<int, double> distances;
  for (auto i = 0; i < graph.num_nodes(); ++i) {
    distances[i] = distance(graph[i].location(), a);
  }

  // Sort the distances and return the lowest.
  using mypair = std::pair<int, double>;
  std::vector<mypair> v(std::begin(distances), std::end(distances));
  std::sort(std::begin(v), std::end(v), [](const mypair &a, const mypair &b){
    return a.second < b.second;
  });

  return graph[v.begin()->first];
}

int waiting_time(map::map_node const &node) {
  return static_cast<int>(node[0].weight());
}

} // namespace pigisland
} // namespace kmint
