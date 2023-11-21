#pragma once

#include <iostream>
#include <array>
#include <complex>

namespace algebra
{
    /// @brief The structure template describes a vector stores `SIZE` entries of type `T`.
    /// @tparam T The type of vector entries.
    /// @tparam SIZE The dimension of the vector.
    template <typename T, size_t SIZE>
    struct vector
    {
        /// @brief The type of vector entries.
        using entry = T;
        /// @brief The reference type of vector entries.
        using reference = entry &;
        /// @brief The constant reference type of vector entries.
        using const_reference = const entry &;

        using array = std::array<entry, SIZE>;
        using array_reference = std::array<entry, SIZE> &;
        using array_const_reference = const std::array<entry, SIZE> &;

        using vec = vector<entry, SIZE>;
        using vec_reference = vec &;
        using vec_const_reference = const vec &;

        vector()
        {
        }

        /// @brief Constructs a vector as a copy of some other vector.
        /// @param vec The vector to copy from.
        vector(vec_const_reference vec)
            : entries(vec.entries)
        {
            std::cout << "Vector get copied." << std::endl;
        }

        /// @brief Constructs a vector with specified entries.
        /// @param entries The array of entries of type `T` and size `SIZE`.
        vector(array_const_reference entries)
            : entries(entries)
        {
        }

        /// @brief Accesses an entry at a specified position.
        /// @param off Position of entry to access.
        /// @return The constant reference of the entry.
        inline constexpr const_reference operator[](size_t off) const
        {
            return entries[off];
        }

        /// @brief Accesses an entry at a specified position.
        /// @param off Position of entry to access.
        /// @return The reference of the entry.
        inline reference operator[](size_t off)
        {
            return entries[off];
        }

        /// @brief Adds a vector to another target vector.
        /// @param right A vector that is of the same type as the parameter of the target vector.
        /// @return A vector that has had the vector specified as a parameter added.
        inline vec_reference operator+=(vec_const_reference right)
        {
            for (size_t i = 0; i < SIZE; i++)
            {
                entries[i] += right[i];
            }
            return *this;
        }

        /// @brief Subtract a vector to another target vector.
        /// @param right A vector that is of the same type as the parameter of the target vector.
        /// @return A vector that has had the vector specified as a parameter subtracted.
        inline vec_reference operator-=(vec_const_reference right)
        {
            for (size_t i = 0; i < SIZE; i++)
            {
                entries[i] -= right[i];
            }
            return *this;
        }

        /// @brief Multiply a scalar to another target vector.
        /// @param right A vector that is of the same type as the parameter of the target vector.
        /// @return A vector that has had the vector specified as a parameter multiplied.
        inline vec_reference operator*=(const_reference right)
        {
            for (size_t i = 0; i < SIZE; i++)
            {
                entries[i] *= right;
            }
            return *this;
        }

        /// @brief Divide a scalar to another target vector.
        /// @param right A vector that is of the same type as the parameter of the target vector.
        /// @return A vector that has had the vector specified as a parameter divided.
        inline vec_reference operator/=(const_reference right)
        {
            entry inverse = static_cast<entry>(1) / right;
            for (size_t i = 0; i < SIZE; i++)
            {
                entries[i] *= inverse;
            }
            return *this;
        }

        /// @brief Tests for equality between two vectors.
        /// @param left A vector to be tested for inequality.
        /// @param right A vector to be tested for inequality.
        /// @return `true` if the numbers are equal and `false` if numbers are not equal.
        friend inline bool operator==(vec_const_reference left, vec_const_reference right)
        {
            for (size_t i = 0; i < SIZE; i++)
            {
                if (left[i] != right[i])
                {
                    return false;
                }
            }
            return true;
        }

        /// @brief Prints specified vector.
        /// @param stream The `ostream`.
        /// @param vec The vector to print.
        /// @return The `ostream`.
        friend std::ostream &operator<<(std::ostream &stream, vec_const_reference vec)
        {
            stream << '(' << vec[0];
            for (size_t i = 1; i < SIZE; i++)
            {
                stream << ',' << ' ' << vec[i];
            }
            stream << ')';
            return stream;
        }

    protected:
        /// @brief The array of entries of this vector.
        array entries;
    };

    /// @brief Tests for equality between two vectors.
    /// @tparam T The type of vector entries.
    /// @tparam SIZE The dimension of two vectors.
    /// @param left A vector to be tested for inequality.
    /// @param right A vector to be tested for inequality.
    /// @return `true` if the numbers are not equal and `false` if numbers are equal.
    template <typename T, size_t SIZE>
    inline bool operator!=(const vector<T, SIZE> &left, const vector<T, SIZE> &right)
    {
        for (size_t i = 0; i < SIZE; i++)
        {
            if (left[i] != right[i])
            {
                return true;
            }
        }
        return false;
    }

    template <typename T, size_t SIZE>
    inline vector<T, SIZE> operator-(const vector<T, SIZE> &vec)
    {
        vector<T, SIZE> temp;
        for (size_t i = 0; i < SIZE; i++)
        {
            temp[i] = -vec[i];
        }
        return temp;
    }

    /// @brief Adds two vectors.
    /// @tparam T The type of vector entries.
    /// @tparam SIZE The dimension of two vectors.
    /// @param left The first vector to be added by the `+` operation.
    /// @param right The second vector to be added by the `+` operation.
    /// @return The sum that results from the addition of the two vectors.
    template <typename T, size_t SIZE>
    inline vector<T, SIZE> operator+(const vector<T, SIZE> &left, const vector<T, SIZE> &right)
    {
        vector<T, SIZE> temp;
        for (size_t i = 0; i < SIZE; i++)
        {
            temp[i] = left[i] + right[i];
        }
        return temp;
    }

    /// @brief Subtracts two vectors.
    /// @tparam T The type of vector entries.
    /// @tparam SIZE The dimension of two vectors.
    /// @param left The first vector to be subtracted by the `-` operation.
    /// @param right The second vector to be subtracted by the `-` operation.
    /// @return The difference that results from the subtraction of `right` from `left`.
    template <typename T, size_t SIZE>
    inline vector<T, SIZE> operator-(const vector<T, SIZE> &left, const vector<T, SIZE> &right)
    {
        vector<T, SIZE> temp;
        for (size_t i = 0; i < SIZE; i++)
        {
            temp[i] = left[i] - right[i];
        }
        return temp;
    }

    /// @brief Multiplies a vector and a scalar.
    /// @tparam T The type of vector entries.
    /// @tparam S The type of the scalar.
    /// @tparam SIZE The dimension of the vector.
    /// @param left The scalar to be multiplied by the `*` operation.
    /// @param right The vector to be multiplied by the `*` operation.
    /// @return The product that results from the multiplication.
    template <typename T, typename S, size_t SIZE>
    inline vector<T, SIZE> operator*(const S &left, const vector<T, SIZE> &right)
    {
        vector<T, SIZE> temp;
        for (size_t i = 0; i < SIZE; i++)
        {
            temp[i] = left * right[i];
        }
        return temp;
    }

    template <typename T, typename S, size_t SIZE>
    inline vector<T, SIZE> operator*(const vector<T, SIZE> &left, const S &right)
    {
        vector<T, SIZE> temp;
        for (size_t i = 0; i < SIZE; i++)
        {
            temp[i] = left[i] * right;
        }
        return temp;
    }

    template <typename T, typename S, size_t SIZE>
    inline vector<T, SIZE> operator/(const vector<T, SIZE> &left, const S &right)
    {
        vector<T, SIZE> temp;
        S inverse = static_cast<S>(1) / right;
        for (size_t i = 0; i < SIZE; i++)
        {
            temp[i] = left[i] * inverse;
        }
        return temp;
    }

    template <typename T, size_t SIZE>
    inline T dot(const vector<T, SIZE> &left, const vector<T, SIZE> &right)
    {
        T dot_product = 0;
        for (size_t i = 0; i < SIZE; i++)
        {
            dot_product += left[i] * right[i];
        }
        return dot_product;
    }

    template <typename T, size_t SIZE>
    inline std::complex<T> dot(const vector<std::complex<T>, SIZE> &left, const vector<std::complex<T>, SIZE> &right)
    {
        std::complex<T> dot_product = 0;
        for (size_t i = 0; i < SIZE; i++)
        {
            dot_product += std::conj(left[i]) * right[i];
        }
        return dot_product;
    }

    template <typename T, size_t SIZE>
    inline T sqr_magnitude(const vector<T, SIZE> &vec)
    {
        T sqr_magnitude = 0;
        for (size_t i = 0; i < SIZE; i++)
        {
            sqr_magnitude += vec[i] * vec[i];
        }
        return sqr_magnitude;
    }

    template <typename T, size_t SIZE>
    inline T sqr_magnitude(const vector<std::complex<T>, SIZE> &vec)
    {
        T sqr_magnitude = 0;
        for (size_t i = 0; i < SIZE; i++)
        {
            const std::complex<T> &entry = vec[i];
            sqr_magnitude += std::real(entry) * std::real(entry) + std::imag(entry) * std::imag(entry);
        }
        return sqr_magnitude;
    }

    template <typename T, size_t SIZE>
    inline T magnitude(const vector<T, SIZE> &vec)
    {
        return sqrt(sqr_magnitude(vec));
    }

    template <typename T, size_t SIZE>
    inline T magnitude(const vector<std::complex<T>, SIZE> &vec)
    {
        return sqrt(sqr_magnitude(vec));
    }

    template <typename T, size_t SIZE>
    inline vector<T, SIZE> normalied(const vector<T, SIZE> &vec)
    {
        return vec / magnitude(vec);
    }
}
