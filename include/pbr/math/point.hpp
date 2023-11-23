#pragma once

#include "vector.hpp"

namespace pbr
{
    struct point : public algebra::vector_base<number, 3, point>
    {
        /// @brief Default point constructor.
        point();

        /// @brief Constructs a vector as a copy of some other vector.
        /// @param p The vector to copy from.
        point(vec_const_reference p);

        /// @brief Constructs a vector with specified entries.
        /// @param x The x entry.
        /// @param y The y entry.
        /// @param z The z entry.
        point(entry x, entry y, entry z);
    };

    std::ostream &operator<<(std::ostream &stream, const point &p);

    point operator+(const point &left, const vector &right);
    point operator-(const point &left, const vector &right);
    vector operator-(const point &left, const point &right);

    constexpr number sqr_distance(const point &left, const point &right);
    constexpr number distance(const point &left, const point &right);

    point lerp(number t, const point &from, const point &to);
}