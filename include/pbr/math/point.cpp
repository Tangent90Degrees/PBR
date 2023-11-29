#include "point.hpp"

namespace pbr
{
    point::point()
    {
    }

    point::point(vec_const_reference p)
        : vector_base(p.entries)
    {
    }

    point::point(entry x, entry y, entry z)
        : vector_base(array({x, y, z}))
    {
    }

    std::ostream &operator<<(std::ostream &stream, const point &p)
    {
        return algebra::operator<<(stream << "point", p);
    }

    number sqr_distance(const point &left, const point &right)
    {
        return sqr_magnitude(left - right);
    }

    number distance(const point &left, const point &right)
    {
        return magnitude(left - right);
    }

    point lerp(number t, const point &from, const point &to)
    {
        return (1 - t) * from + t * to;
    }
}