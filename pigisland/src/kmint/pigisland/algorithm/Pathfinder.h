#ifndef KMINT_ASESSMENT_PATHFINDER_H
#define KMINT_ASESSMENT_PATHFINDER_H

#include <kmint/map/map.hpp>
#include <map>

using namespace kmint::graph;

namespace kmint
{
    namespace pigisland
    {
        class Pathfinder
        {
        public:
            virtual std::vector<int> perform(const map::map_graph &graph, map::map_node const &source,
                                             map::map_node const &destination) = 0;
            virtual ~Pathfinder() = default;
            void tag(map::map_graph &graph, std::vector<int> &path, node_tag t = node_tag::visited) const;
        protected:
            virtual int get_lowest(const map::map_graph &graph, const std::vector<int> &closedList,
                                   std::map<int, double> &distances) const;

            virtual std::vector<int> reconstruct_path(std::map<int, int> &cameFrom, int current, int destination) const;
        };
    }
}


#endif //KMINT_ASESSMENT_PATHFINDER_H
