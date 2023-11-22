
#include <iostream>
#include "include/pbr/math/vector.hpp"
#include "include/pbr.hpp"

int main()
{
    pbr::point vecA = {1, 2, 3};
    pbr::point vecB = {1, 5, 3};

    std::cout << 1 << std::endl;
    std::cout << (vecA - vecB) << std::endl;
    // std::cout << matT * vecA << std::endl;
    std::cin.get();
}