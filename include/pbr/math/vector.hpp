#pragma once

#include "../core/core.hpp"
#include "../../foundation/vector_base.hpp"

namespace pbr
{
    constexpr const size_t X = 0;
    constexpr const size_t Y = 1;
    constexpr const size_t Z = 2;

    /// @brief The 3-dimentional numberic vector for PBR computing.
    struct vector : public algebra::vector_base<number, 3, vector>
    {
        /// @brief Default vector constructor.
        vector();

        /// @brief Constructs a vector as a copy of some other vector.
        /// @param v The vector to copy from.
        vector(vec_const_reference v);

        /// @brief Constructs a vector with specified entries.
        /// @param x The x entry.
        /// @param y The y entry.
        /// @param z The z entry.
        vector(number x, number y, number z);
    };

    std::ostream &operator<<(std::ostream &stream, const vector &v);
}