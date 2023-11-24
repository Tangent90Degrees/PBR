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

    matrix::matrix(const vector &x_axis, const vector &y_axis, const vector &z_axis)
        : matrix(x_axis[X], y_axis[X], z_axis[X],
                 x_axis[Y], y_axis[Y], z_axis[Y],
                 x_axis[Z], y_axis[Z], z_axis[Z])
    {
    }

    matrix::matrix(const vector &x_axis, const vector &y_axis)
        : matrix(x_axis, y_axis, cross(x_axis, y_axis).normalize())
    {
    }

    vector operator*(const matrix &left, const vector &right)
    {
        return algebra::operator* <number, 3, 3, matrix, vector, vector>(left, right);
    }

} // namespace pbr
