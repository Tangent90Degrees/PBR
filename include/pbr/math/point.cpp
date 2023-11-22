#include "point.hpp"

namespace pbr
{
    point::point()
    {
    }

    point::point(const point &p)
        : algebra::vector_base<number, 3, point>(p.entries)
    {
    }

    // point::point(number x, number y, number z)
    //     : algebra::vector_base<number, 3, point>({{{x, y, z}}})
    // {
    // }

    point::point(const algebra::vector_base<number, 3, point> &vec)
        : algebra::vector_base<number, 3, point>(vec)
    {
    }

    // point operator+(const point &left, const vector &right)
    // {
    //     return point(left[X] + right[X],
    //                  left[Y] + right[Y],
    //                  left[Z] + right[Z]);
    // }

    // point operator-(const point &left, const vector &right)
    // {
    //     return point(left[X] - right[X],
    //                  left[Y] - right[Y],
    //                  left[Z] - right[Z]);
    // }

    // vector operator-(const point &left, const point &right)
    // {
    //     return vector(left[X] - right[X],
    //                   left[Y] - right[Y],
    //                   left[Z] - right[Z]);
    // }

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