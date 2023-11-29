#pragma once

#include <vector>
#include "vector_base.hpp"

namespace algebra
{
    template <typename T, size_t ROW, size_t COL, typename VEC>
    struct matrix_base
    {
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
        using column_reference = column &;
        using column_const_reference = const column &;

        using block = std::array<row, ROW>;
        using block_reference = block &;
        using block_const_reference = const block &;

        using mat = VEC;
        using mat_reference = mat &;
        using mat_const_reference = const mat &;

        matrix_base()
        {
        }

        /// @brief Constructs a vector as a copy of some other vector.
        /// @param vec The vector to copy from.
        matrix_base(mat_const_reference mat)
            : entries(mat.entries)
        {
            std::cout << "Matrix get copied." << std::endl;
        }

        /// @brief Constructs a vector with specified entries.
        /// @param entries The array of entries of type `T` and size `SIZE`.
        matrix_base(block_const_reference entries)
            : entries(entries)
        {
        }

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

    protected:
        block entries;
    };

    template <typename T, size_t M, size_t N, typename MAT>
    std::ostream &operator<<(std::ostream &stream, const matrix_base<T, M, N, MAT> &m)
    {
        for (size_t i = 0; i < M; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                stream << m[i][j] << '\t';
            }
            stream << std::endl;
        }
        return stream;
    }

    template <typename T, size_t M, size_t N, typename MAT>
    inline bool operator==(const matrix_base<T, M, N, MAT> &left, const matrix_base<T, M, N, MAT> &right)
    {
        for (size_t i = 0; i < M; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                if (left[i][j] != right[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    template <typename T, size_t M, size_t N, typename MAT>
    inline bool operator!=(const matrix_base<T, M, N, MAT> &left, const matrix_base<T, M, N, MAT> &right)
    {
        for (size_t i = 0; i < M; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                if (left[i][j] != right[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    }

    template <typename T, size_t M, size_t N, typename MAT, typename VEC_M, typename VEC_N>
    inline VEC_M operator*(const matrix_base<T, M, N, MAT> &left, const vector_base<T, N, VEC_N> &right)
    {
        VEC_M product;
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

    template <typename T, size_t L, size_t M, size_t N, typename MAT_L, typename MAT_R, typename MAT = MAT_L>
    inline MAT operator*(const matrix_base<T, L, M, MAT_L> &left, const matrix_base<T, M, N, MAT_R> &right)
    {
        MAT product;
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

    template <typename T, size_t N, typename MAT>
    inline T trace(const matrix_base<T, N, N, MAT> &m)
    {
        T trace = 0;
        for (size_t i = 0; i < N; i++)
        {
            trace += m[i][i];
        }
        return trace;
    }

} // namespace algebra
