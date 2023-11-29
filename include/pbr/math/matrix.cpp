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

    // matrix::matrix(const vector &x_axis, const vector &y_axis)
    //     : matrix(x_axis, y_axis, cross(x_axis, y_axis).normalize())
    // {
    // }

    vector operator*(const matrix &left, const vector &right)
    {
        return algebra::operator* <number, 3, 3, matrix, vector, vector>(left, right);
    }

    matrix operator*(const matrix &left, const matrix &right)
    {
        return algebra::operator*(left, right);
        // number xx = left[X][X] * right[X][X] + left[X][Y] * right[Y][X] + left[X][Z] * right[Z][X];
        // number xy = left[X][X] * right[X][Y] + left[X][Y] * right[Y][Y] + left[X][Z] * right[Z][Y];
        // number xz = left[X][X] * right[X][Z] + left[X][Y] * right[Y][Z] + left[X][Z] * right[Z][Z];
        // number yx = left[Y][X] * right[X][X] + left[Y][Y] * right[Y][X] + left[Y][Z] * right[Z][X];
        // number yy = left[Y][X] * right[X][Y] + left[Y][Y] * right[Y][Y] + left[Y][Z] * right[Z][Y];
        // number yz = left[Y][X] * right[X][Z] + left[Y][Y] * right[Y][Z] + left[Y][Z] * right[Z][Z];
        // number zx = left[Z][X] * right[X][X] + left[Z][Y] * right[Y][X] + left[Z][Z] * right[Z][X];
        // number zy = left[Z][X] * right[X][Y] + left[Z][Y] * right[Y][Y] + left[Z][Z] * right[Z][Y];
        // number zz = left[Z][X] * right[X][Z] + left[Z][Y] * right[Y][Z] + left[Z][Z] * right[Z][Z];
        // return matrix(xx, xy, xz,
        //               yx, yy, yz,
        //               zx, zy, zz);
    }

    number det(const matrix &m)
    {
        return m[X][X] * m[Y][Y] * m[Z][Z] +
               m[X][Y] * m[Y][Z] * m[Z][X] +
               m[X][Z] * m[Y][X] * m[Z][Y] -
               m[X][Z] * m[Y][Y] * m[Z][X] -
               m[X][Y] * m[Y][X] * m[Z][Z] -
               m[X][X] * m[Y][Z] * m[Z][Y];
    }

    number trace(const matrix &m)
    {
        return m[X][X] + m[Y][Y] + m[Z][Z];
    }

    matrix inverse(const matrix &m)
    {
        number determinant = det(m);
        number xx = (m[Y][Y] * m[Z][Z] - m[Y][Z] * m[Z][Y]) / determinant;
        number xy = (m[Y][Z] * m[Z][X] - m[Y][X] * m[Z][Z]) / determinant;
        number xz = (m[Y][X] * m[Z][Y] - m[Y][Y] * m[Z][X]) / determinant;
        number yx = (m[Z][Y] * m[X][Z] - m[Z][Z] * m[X][Y]) / determinant;
        number yy = (m[Z][Z] * m[X][X] - m[Z][X] * m[X][Z]) / determinant;
        number yz = (m[Z][X] * m[X][Y] - m[Z][Y] * m[X][X]) / determinant;
        number zx = (m[X][Y] * m[Y][Z] - m[X][Z] * m[Y][Y]) / determinant;
        number zy = (m[X][Z] * m[Y][X] - m[X][X] * m[Y][Z]) / determinant;
        number zz = (m[X][X] * m[Y][Y] - m[X][Y] * m[Y][X]) / determinant;
        return matrix(xx, yx, zx,
                      xy, yy, zy,
                      xz, yz, zz);
    }

} // namespace pbr
