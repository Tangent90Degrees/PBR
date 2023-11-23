#pragma once

#include "../core/core.hpp"
#include "../../foundation/vector_base.hpp"

namespace pbr
{
    constexpr size_t X = 0;
    constexpr size_t Y = 1;
    constexpr size_t Z = 2;

    /// @brief The 3-dimentional numberic vector for PBR computing.
    struct vector : public algebra::vector_base<number, 3, vector>
    {
        /// @brief Default vector constructor.
        constexpr vector();

        /// @brief Constructs a vector as a copy of some other vector.
        /// @param v The vector to copy from.
        constexpr vector(vec_const_reference v);

        /// @brief Constructs a vector with specified entries.
        /// @param x The x entry.
        /// @param y The y entry.
        /// @param z The z entry.
        constexpr vector(entry x, entry y, entry z);
    };

    std::ostream &operator<<(std::ostream &stream, const vector &v);
}