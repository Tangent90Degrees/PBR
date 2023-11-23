
#include <iostream>
#include "include/pbr/math/vector.hpp"
#include "include/pbr.hpp"

int main()
{
    const pbr::vector vecA = {1, 2, 3};
    pbr::vector vecB = {1, 5, 3};

    pbr::matrix mat = {1, 2, 3,
                       3, 7, 8,
                       9, 3, 6};

    vecB = vecA;

    std::cout << pbr::vector(0, 5, 6) + pbr::vector(0, 5, 6) << std::endl;
    // std::cout << vecB.face_toward(-vecA) << std::endl;
    std::cout << vecA[pbr::X] << std::endl;
    std::cin.get();
}