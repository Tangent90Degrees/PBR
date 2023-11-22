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

    point::point(number x, number y, number z)
        : vector_base(array({x, y, z}))
    {
    }

    std::ostream &operator<<(std::ostream &stream, const point &p)
    {
        return algebra::operator<<(stream << "point", p);
    }

    point operator+(const point &left, const vector &right)
    {
        return algebra::operator+(left, right);
    }

    point operator-(const point &left, const vector &right)
    {
        return algebra::operator-(left, right);
    }

    vector operator-(const point &left, const point &right)
    {
        return algebra::operator- <number, 3, point, point, vector>(left, right);
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