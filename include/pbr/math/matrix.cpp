#include "matrix.hpp"

namespace pbr
{
    matrix::matrix()
    {
    }

    matrix::matrix(mat_const_reference m)
        : matrix_base(m.entries)
    {
    }

    matrix::matrix(entry xx, entry xy, entry xz,
                   entry yx, entry yy, entry yz,
                   entry zx, entry zy, entry zz)
        : matrix_base({{{xx, xy, xz},
                        {yx, yy, yz},
                        {zx, zy, zz}}})
    {
    }

    vector operator*(const matrix &left, const vector &right)
    {
        return algebra::operator* <number, 3, 3, matrix, vector, vector>(left, right);
    }

} // namespace pbr
