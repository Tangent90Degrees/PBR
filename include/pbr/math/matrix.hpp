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
    };
    
    // static constexpr matrix ZERO(0);

    vector operator*(const matrix &left, const vector &right);

} // namespace pbr
