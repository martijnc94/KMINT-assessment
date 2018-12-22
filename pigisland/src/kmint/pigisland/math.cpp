#include "math.h"

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
    }
}