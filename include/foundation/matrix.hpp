#pragma once

#include "vector.hpp"

namespace algebra
{
    template <typename T, size_t ROW, size_t COL>
    struct matrix
    {
        /// @brief The type of vector entries.
        using entry = float;
        /// @brief The reference type of vector entries.
        using reference = entry &;
        /// @brief The constant reference type of vector entries.
        using const_reference = const entry &;

        using row_line = std::array<entry, COL>;
        using row_line_reference = row_line &;
        using row_line_const_reference = const row_line &;

        using column_line = std::array<entry, ROW>;
        using column_line_reference = column_line &;
        using column_line_const_reference = const column_line &;

        using block = std::array<row_line, ROW>;
        using block_reference = block &;
        using block_const_reference = const block &;

        using mat = matrix;
        using mat_reference = mat &;
        using mat_const_reference = const mat &;

        matrix()
        {
        }

        /// @brief Constructs a vector as a copy of some other vector.
        /// @param vec The vector to copy from.
        matrix(mat_const_reference mat)
            : entries(mat.entries)
        {
            std::cout << "Matrix get copied." << std::endl;
        }

        /// @brief Constructs a vector with specified entries.
        /// @param entries The array of entries of type `T` and size `SIZE`.
        matrix(block_const_reference entries)
            : entries(entries)
        {
        }

        /// @brief Accesses an entry at a specified position.
        /// @param off Position of entry to access.
        /// @return The constant reference of the entry.
        inline constexpr row_line_const_reference operator[](size_t off) const
        {
            return entries[off];
        }

        /// @brief Accesses an entry at a specified position.
        /// @param off Position of entry to access.
        /// @return The reference of the entry.
        inline row_line_reference operator[](size_t off)
        {
            return entries[off];
        }

    protected:
        block entries;
    };

    template <typename T, size_t M, size_t N, typename VEC_M, typename VEC_N>
    inline vector_base<T, M, VEC_M> operator*(const matrix<T, M, N> &left, const vector_base<T, N, VEC_N> &right)
    {
        vector_base<T, M, VEC_M> product;
        for (size_t i = 0; i < M; i++)
        {
            T temp = 0;
            for (size_t j = 0; j < N; j++)
            {
                temp += left[i][j] * right[j];
            }
            product[i] = temp;
        }
        return product;
    }

    template <typename T, size_t L, size_t M, size_t N>
    inline matrix<T, L, N> operator*(const matrix<T, L, M> &left, const matrix<T, M, N> &right)
    {
        matrix<T, L, N> product;
        for (size_t i = 0; i < L; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                T temp = 0;
                for (size_t k = 0; k < M; k++)
                {
                    temp += left[i][k] * right[k][j];
                }
                product[i][j] = temp;
            }
        }
        return product;
    }

} // namespace algebra
