
#include <iostream>
#include "include/pbr/math/vector.hpp"
#include "include/pbr.hpp"

int main()
{
    const pbr::vector vecA = {1, 2, 3};
    pbr::vector vecB = {1, 5, 3};

    pbr::matrix mat = {1, 6, 7,
                       0, 1, 3,
                       8, 2, 1};

    vecB = vecA;

    std::cout << mat * pbr::inverse(mat) << std::endl;
    // std::cout << vecB.face_toward(-vecA) << std::endl;
    std::cout << vecA[pbr::X] << std::endl;
    std::cin.get();
}