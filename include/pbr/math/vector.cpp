#include "vector.hpp"

namespace pbr
{
    vector::vector()
    {
    }

    vector::vector(const vector &vec)
        : algebra::vector_base<number, 3, vector>(vec.entries)
    {
    }

    vector::vector(number x, number y, number z)
        : algebra::vector_base<number, 3, vector>({{{x, y, z}}})
    {
    }

    std::ostream &operator<<(std::ostream &stream, const vector &vec)
    {
        return algebra::operator<<(stream << "vector", vec);
    }
}