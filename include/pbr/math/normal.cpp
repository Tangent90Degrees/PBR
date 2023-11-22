#include "normal.hpp"

namespace pbr
{
    normal::normal()
    {
    }

    normal::normal(vec_const_reference n)
        : vector_base(n.entries)
    {
    }

    normal::normal(number x, number y, number z)
        : vector_base(array({x, y, z}))
    {
    }

    normal operator-(const normal &right)
    {
        return normal(-right[X], -right[Y], -right[Z]);
    }
}