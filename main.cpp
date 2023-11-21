
#include <iostream>
#include "include/pbr/math/vector.hpp"

int main()
{
    algebra::vector<pbr::number, 3> vecA = {{1, 2, 3}};
    algebra::vector<pbr::number, 3> vecB = {{1, 5, 3}};

    algebra::vector<std::complex<float>, 3> complex_vec = {{{
        {1, 2}, {3, 4}, {5, 6}
    }}};

    std::cout << algebra::normalied(complex_vec) << std::endl;
    std::cout << (vecA == vecB) << std::endl;
    std::cin.get();
}