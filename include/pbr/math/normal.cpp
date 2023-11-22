#include "normal.hpp"

namespace pbr
{
    normal::normal()
    {
    }

    normal::normal(const normal &n)
        : algebra::vector_base<number, 3, normal>(n.entries)
    {
    }

    normal::normal(number x, number y, number z)
        : algebra::vector_base<number, 3, normal>({{{x, y, z}}})
    {
    }

    normal &normal::face_toward(const algebra::vector_base<number, 3, normal> &direction)
    {
        if (dot(*this, direction) < 0)
        {
            *this = -*this;
        }
        return *this;
    }

    normal normal::face_toward(const algebra::vector_base<number, 3, normal> &direction) const
    {
        return dot(*this, direction) < 0 ? -*this : *this;
    }

    normal operator-(const normal &right)
    {
        return normal(-right[X], -right[Y], -right[Z]);
    }
}