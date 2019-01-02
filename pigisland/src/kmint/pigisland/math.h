#ifndef KMINT_ASESSMENT_MATH_H
#define KMINT_ASESSMENT_MATH_H

#include <kmint/math/vector2d.hpp>

namespace kmint {
    namespace pigisland
    {
        class EntityWithForce;

        double vectorLength(const math::vector2d &v);
        math::vector2d vectorNormalize(const math::vector2d &v);
        math::vector2d vectorPerp(const math::vector2d &v);
        void wrapAround(EntityWithForce &entity);
        double vectorDistanceSquared(const math::vector2d &v1, const math::vector2d &v2);
    }
}

#endif //KMINT_ASESSMENT_MATH_H
