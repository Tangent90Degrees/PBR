#include "normal.hpp"

namespace pbr
{
    normal::normal()
    {
    }

    normal::normal(const normal &normal)
        : algebra::vector<number, 3>(normal.entries)
    {
    }

    normal::normal(number x, number y, number z)
        : algebra::vector<number, 3>({x, y, z})
    {
    }

    normal::normal(const algebra::vector<number, 3> &vec)
        : algebra::vector<number, 3>(vec)
    {
    }

    normal &normal::face_toward(const algebra::vector<number, 3> &direction)
    {
        if (dot(*this, direction) < 0)
        {
            *this = -*this;
        }
        return *this;
    }

    normal normal::face_toward(const algebra::vector<number, 3> &direction) const
    {
        return dot(*this, direction) < 0 ? -*this : *this;
    }

    normal operator-(const normal &right)
    {
        return normal(-right[X], -right[Y], -right[Z]);
    }
}