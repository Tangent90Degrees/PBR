#include "vector.hpp"

namespace pbr
{
    constexpr vector::vector()
    {
    }

    constexpr vector::vector(vec_const_reference v)
        : vector_base(v.entries)
    {
    }

    constexpr vector::vector(entry x, entry y, entry z)
        : vector_base(array({x, y, z}))
    {
    }

    std::ostream &operator<<(std::ostream &stream, const vector &v)
    {
        return algebra::operator<<(stream << "vector", v);
    }
}