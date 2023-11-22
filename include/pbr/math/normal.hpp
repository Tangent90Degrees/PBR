#pragma once

#include "vector.hpp"

namespace pbr
{
    struct normal : public algebra::vector_base<number, 3, normal>
    {
        /// @brief Default normal constructor.
        normal();

        /// @brief Constructs a normal as a copy of some other normal.
        /// @param n The normal to copy from.
        normal(vec_const_reference n);

        /// @brief Constructs a normal with specified entries.
        /// @param x The x entry.
        /// @param y The y entry.
        /// @param z The z entry.
        normal(number x, number y, number z);

        template <typename VEC>
        normal &face_toward(const algebra::vector_base<number, 3, VEC> &direction)
        {
            if (dot(*this, direction) < 0)
            {
                *this = -*this;
            }
            return *this;
        }

        template <typename VEC>
        normal face_toward(const algebra::vector_base<number, 3, VEC> &direction) const
        {
            return dot(*this, direction) < 0 ? -*this : *this;
        }
    };

    normal operator-(const normal &right);
}