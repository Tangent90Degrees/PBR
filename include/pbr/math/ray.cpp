#include "ray.hpp"

namespace pbr
{
    ray::ray()
    {
    }

    ray::ray(const point &origin, const vector &direction)
        : origin(origin), direction(direction)
    {
    }

    // point ray::operator()(number t) const
    // {
    //     return origin + t * direction;
    // }
}