/* Standalone example. */
#include <algorithm>
#include <vector>
#include <iostream>
int main()
{
    std::vector<int> data{58, 10, 8};
    std::sort(data.begin(), data.end());
    std::cout << data.front() << '\n';
}
