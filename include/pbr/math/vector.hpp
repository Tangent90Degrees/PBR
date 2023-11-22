#pragma once

#include "../core/core.hpp"
#include "../../foundation/vector.hpp"

namespace pbr
{
    constexpr const size_t X = 0;
    constexpr const size_t Y = 1;
    constexpr const size_t Z = 2;

    /// @brief The 3-dimentional numberic vector for PBR computing.
    struct vector : public algebra::vector<number, 3>
    {
        /// @brief Default vector constructor.
        vector();

        /// @brief Constructs a vector as a copy of some other vector.
        /// @param vec The vector to copy from.
        vector(const vector &vec);

        /// @brief Constructs a vector with specified entries.
        /// @param x The x entry.
        /// @param y The y entry.
        /// @param z The z entry.
        vector(number x, number y, number z);

        /// @brief Constructs a vector as a copy of some abstract vector.
        /// @param vec The vector to copy from.
        vector(const algebra::vector<number, 3> &vec);
        
    };

    bool operator==(const vector &left, const vector &right);
    bool operator!=(const vector &left, const vector &right);

    vector operator+(const vector &right);
    vector operator-(const vector &right);

    vector operator+(const vector &left, const vector &right);
    vector operator-(const vector &left, const vector &right);
    vector operator*(number left, const vector &right);
    vector operator*(const vector &left, number right);
    vector operator/(const vector &left, number right);

    number dot(const vector &left, const vector &right);
    vector cross(const vector &left, const vector &right);

    number sqr_magnitude(const vector &vec);
    number magnitude(const vector &vec);

    vector normalized(const vector &vec);
}