
#include <iostream>
#include "include/pbr/math/vector.hpp"

int main()
{
    pbr::vector vecA = {1, 2, 3};
    pbr::vector vecB = {1, 5, 3};

    std::cout << algebra::magnitude(vecA + vecB) << std::endl;
    // std::cout << matT * vecA << std::endl;
    std::cin.get();
}