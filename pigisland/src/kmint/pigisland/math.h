#ifndef KMINT_ASESSMENT_MATH_H
#define KMINT_ASESSMENT_MATH_H

#include <kmint/math/vector2d.hpp>
#include <kmint/pigisland/force/EntityWithForce.h>

namespace kmint {
    namespace pigisland
    {
        double vectorLength(const math::vector2d &v);
        math::vector2d vectorNormalize(const math::vector2d &v);
        math::vector2d vectorPerp(const math::vector2d &v);
        void wrapAround(EntityWithForce &entity);
    }
}

#endif //KMINT_ASESSMENT_MATH_H
