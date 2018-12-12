#ifndef KMINT_ASESSMENT_ASTAR_H
#define KMINT_ASESSMENT_ASTAR_H

#include "Pathfinder.h"

namespace kmint
{
    namespace pigisland
    {
        class Astar : public Pathfinder
        {
        public:
            std::vector<int> perform(map::map_graph &graph, map::map_node const &source, map::map_node const &destination) override;
        private:
            const double heurestic(const map::map_node &a, const map::map_node &b) const;
        };
    }
}

#endif //KMINT_ASESSMENT_ASTAR_H
