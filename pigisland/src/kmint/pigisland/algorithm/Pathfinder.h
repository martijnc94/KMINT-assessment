#ifndef KMINT_ASESSMENT_PATHFINDER_H
#define KMINT_ASESSMENT_PATHFINDER_H

#include <kmint/map/map.hpp>
#include <map>

namespace kmint
{
    namespace pigisland
    {
        class Pathfinder
        {
            virtual std::vector<int> perform(map::map_graph &graph, map::map_node const &source, map::map_node const &destination) = 0;

        protected:
            virtual int get_lowest(map::map_graph &graph, const std::vector<int> &closedList,
                                   std::map<int, double> &distances) const;

            virtual std::vector<int> reconstruct_path(std::map<int, int> &cameFrom, int current, int destination) const;
        };
    }
}


#endif //KMINT_ASESSMENT_PATHFINDER_H
