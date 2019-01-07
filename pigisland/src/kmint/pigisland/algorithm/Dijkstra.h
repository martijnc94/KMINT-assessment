#ifndef KMINT_ASESSMENT_DIJKSTRA_H
#define KMINT_ASESSMENT_DIJKSTRA_H

#include "Pathfinder.h"

namespace kmint
{
    namespace pigisland
    {
        class Dijkstra : public Pathfinder
        {
        public:
            ~Dijkstra() = default;
            std::vector<int> perform(const map::map_graph &graph, map::map_node const &source,
                                     map::map_node const &destination) override;
        };
    }
}

#endif //KMINT_ASESSMENT_DIJKSTRA_H
