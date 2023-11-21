#pragma once

#include "vector.hpp"

namespace pbr
{
    struct point : public algebra::vector<number, 3>
    {
        /// @brief Default point constructor.
        point();

        /// @brief Constructs a vector as a copy of some other vector.
        /// @param vec The vector to copy from.
        point(const point &vec);

        /// @brief Constructs a vector with specified entries.
        /// @param x The x entry.
        /// @param y The y entry.
        /// @param z The z entry.
        point(number x, number y, number z);

        /// @brief Constructs a vector as a copy of some abstract vector.
        /// @param vec The vector to copy from.
        point(const algebra::vector<number, 3> &vec);
    };

    point operator+(const point &left, const vector &right);
    point operator-(const point &left, const vector &right);
    vector operator-(const point &left, const point &right);

    number sqr_distance(const point &left, const point &right);
    number distance(const point &left, const point &right);

    point lerp(number t, const point &from, const point &to);
}