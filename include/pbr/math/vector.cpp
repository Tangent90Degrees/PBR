#include "vector.hpp"

namespace pbr
{
    vector::vector()
    {
    }

    vector::vector(vec_const_reference v)
        : vector_base(v.entries)
    {
    }

    vector::vector(number x, number y, number z)
        : vector_base(array({x, y, z}))
    {
    }

    std::ostream &operator<<(std::ostream &stream, const vector &v)
    {
        return algebra::operator<<(stream << "vector", v);
    }
}