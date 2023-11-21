#pragma once

#include "point.hpp"

namespace pbr
{
    struct ray
    {
        ray();
        ray(const point &origin, const vector &direction);

        point origin;
        vector direction;

        point operator()(number t) const;

        friend point operator+(const ray &left, const ray &right);
    };
}