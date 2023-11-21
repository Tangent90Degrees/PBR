#include "vector.hpp"

namespace pbr
{
    vector::vector()
    {
    }

    vector::vector(const vector &vec)
        : algebra::vector<number, 3>(vec.entries)
    {
    }

    vector::vector(number x, number y, number z)
        : algebra::vector<number, 3>({x, y, z})
    {
    }

    vector::vector(const algebra::vector<number, 3> &vec)
        : algebra::vector<number, 3>(vec)
    {
    }

    bool operator==(const vector &left, const vector &right)
    {
        return left[X] == right[X] &&
               left[Y] == right[Y] &&
               left[Z] == right[Z];
    }

    bool operator!=(const vector &left, const vector &right)
    {
        return left[X] != right[X] ||
               left[Y] != right[Y] ||
               left[Z] != right[Z];
    }

    vector operator+(const vector &left, const vector &right)
    {
        return vector(left[X] + right[X],
                      left[Y] + right[Y],
                      left[Z] + right[Z]);
    }

    vector operator-(const vector &left, const vector &right)
    {
        return vector(left[X] - right[X],
                      left[Y] - right[Y],
                      left[Z] - right[Z]);
    }

    vector operator*(number left, const vector &right)
    {
        return vector(left * right[X],
                      left * right[Y],
                      left * right[Z]);
    }

    vector operator*(const vector &left, number right)
    {
        return vector(left[X] * right,
                      left[Y] * right,
                      left[Z] * right);
    }

    vector operator/(const vector &left, number right)
    {
        return vector(left[X] / right,
                      left[Y] / right,
                      left[Z] / right);
    }

    number dot(const vector &left, const vector &right)
    {
        return left[X] * right[X] +
               left[Y] * right[Y] +
               left[Z] * right[Z];
    }

    vector cross(const vector &left, const vector &right)
    {
        return vector(left[Y] * right[Z] - right[Z] * left[Y],
                      left[Z] * right[X] - right[X] * left[Z],
                      left[X] * right[Y] - right[Y] * left[X]);
    }

    number sqr_magnitude(const vector &vec)
    {
        return dot(vec, vec);
    }

    number magnitude(const vector &vec)
    {
        return sqrt(sqr_magnitude(vec));
    }

    vector normalized(const vector &vec)
    {
        return vec / magnitude(vec);
    }
}