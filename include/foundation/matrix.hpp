#pragma once

#include "vector.hpp"

namespace algebra
{
    struct matrix
    {
        static const int ROW = 3;
        static const int COL = 3;

        /// @brief The type of vector entries.
        using entry = float;
        /// @brief The reference type of vector entries.
        using reference = entry &;
        /// @brief The constant reference type of vector entries.
        using const_reference = const entry &;

        using row = std::array<entry, COL>;
        using row_reference = row &;
        using row_const_reference = const row &;

        using column = std::array<entry, ROW>;

        using mat = std::array<row, ROW>;
        using mat_reference = mat &;
        using mat_const_reference = const mat &;

        using row_vec = vector<entry, ROW>;
        using row_vec_reference = row_vec &;
        using row_vec_const_reference = const row_vec &;

        using column_vec = vector<entry, ROW>;
        using column_vec_reference = column_vec &;
        using column_vec_const_reference = const column_vec &;

        /// @brief Accesses an entry at a specified position.
        /// @param off Position of entry to access.
        /// @return The constant reference of the entry.
        inline constexpr row_const_reference operator[](size_t off) const
        {
            return entries[off];
        }

        /// @brief Accesses an entry at a specified position.
        /// @param off Position of entry to access.
        /// @return The reference of the entry.
        inline row_reference operator[](size_t off)
        {
            return entries[off];
        }

        inline row_vec row(size_t off) const
        {
            return entries[off];
        }

        inline column_vec column(size_t off) const
        {
            column column;
            for (size_t i = 0; i < ROW; i++)
            {
                column[i] = entries[i][off];
            }
            return column;
        }

    protected:
        mat entries;
    };

} // namespace algebra
