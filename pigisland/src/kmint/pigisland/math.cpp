#include "math.h"
#include <kmint/pigisland/force/EntityWithForce.h>
#include <kmint/random.hpp>

namespace kmint {
    namespace pigisland
    {
        double vectorLength(const math::vector2d &v)
        {
            return sqrt(pow(v.x(), 2) + pow(v.y(), 2));
        }

        math::vector2d vectorNormalize(const math::vector2d &v)
        {
            auto length = static_cast<float>(sqrt(pow(v.x(), 2) + pow(v.y(), 2)));

            return math::vector2d{v.x() / length, v.y() / length};
        }

        double vectorDistanceSquared(const math::vector2d &v1, const math::vector2d &v2)
        {
            double ySeperation = v2.y() - v1.y();
            double xSeperation = v2.x() - v1.x();

            return (ySeperation * ySeperation) + (xSeperation * xSeperation);
        }

        math::vector2d vectorPerp(const math::vector2d &v)
        {
            auto vector = math::vector2d{};
            vector.x(-v.y());
            vector.y(v.x());

            return vector;
        }

        void wrapAround(EntityWithForce &entity)
        {
            if (entity.location().x() > 1024) {
                auto loc = entity.location();
                loc.x(24);
                entity.setLocation(loc);
            }

            if (entity.location().x() < 0) {
                auto loc = entity.location();
                loc.x(1000);
                entity.setLocation(loc);
            }

            if (entity.location().y() < 0) {
                auto loc = entity.location();
                loc.y(744);
                entity.setLocation(loc);
            }

            if (entity.location().y() > 768) {
                auto loc = entity.location();
                loc.y(24);
                entity.setLocation(loc);
            }
        }

        math::vector2d random_vector()
        {
            auto x = random_scalar(100, 924);
            auto y = random_scalar(50, 728);
            return {x, y};
        }
    }
}