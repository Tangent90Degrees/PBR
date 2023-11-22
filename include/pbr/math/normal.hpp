#pragma once

#include "vector.hpp"

namespace pbr
{
    struct normal : public algebra::vector_base<number, 3, normal>
    {
        /// @brief Default normal constructor.
        normal();

        /// @brief Constructs a normal as a copy of some other normal.
        /// @param normal The normal to copy from.
        normal(const normal &normal);

        /// @brief Constructs a normal with specified entries.
        /// @param x The x entry.
        /// @param y The y entry.
        /// @param z The z entry.
        normal(number x, number y, number z);

        normal &face_toward(const algebra::vector_base<number, 3, normal> &direction);
        normal face_toward(const algebra::vector_base<number, 3, normal> &direction) const;
    };

    normal operator-(const normal &right);
}