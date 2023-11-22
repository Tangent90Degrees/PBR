
#include <iostream>
#include "include/pbr/math/vector.hpp"
#include "include/pbr.hpp"

int main()
{
    pbr::vector vecA = {1, 2, 3};
    pbr::normal vecB = {1, 5, 3};

    pbr::matrix mat = {1, 2, 3,
                       3, 7, 8,
                       9, 3, 6};

    std::cout << 1 << std::endl;
    // std::cout << vecB.face_toward(-vecA) << std::endl;
    // std::cout << matT * vecA << std::endl;
    std::cin.get();
}