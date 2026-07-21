#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <limits>
#include <set>

int main()
{
    long long n{}, r{};
    std::cin >> n >> r;

    if (n >= 10) {
        std::cout << r << std::endl;
    } else {
        std::cout << (r + 100 * (10 - n)) << std::endl;
    }

    return 0;
}
