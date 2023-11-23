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
    {
        entries[X] = {xx, xy, xz};
        entries[Y] = {yx, yy, yz};
        entries[Z] = {zx, zy, zz};
    }

    matrix::matrix(entry d)
        : matrix(d, 0, 0,
                 0, d, 0,
                 0, 0, d)
    {
    }

    vector operator*(const matrix &left, const vector &right)
    {
        return algebra::operator* <number, 3, 3, matrix, vector, vector>(left, right);
    }

} // namespace pbr
