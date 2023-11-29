#pragma once

#include "../core/core.hpp"
#include "../../foundation/matrix_base.hpp"
#include "vector.hpp"

namespace pbr
{
    struct matrix : public algebra::matrix_base<number, 3, 3, matrix>
    {
        matrix();
        matrix(mat_const_reference m);
        matrix(entry xx, entry xy, entry xz,
               entry yx, entry yy, entry yz,
               entry zx, entry zy, entry zz);
        matrix(entry d);
        matrix(const vector &x_axis, const vector &y_axis, const vector &z_axis);
        // matrix(const vector &x_axis, const vector &y_axis);
    };

    vector operator*(const matrix &left, const vector &right);
    matrix operator*(const matrix &left, const matrix &right);

    number det(const matrix &m);
    number trace(const matrix &m);

    matrix inverse(const matrix &m);

} // namespace pbr
