#include <algorithm>
#include <vector>
#include <iostream>
int main()
{
    std::vector<int> data{18, 32, 3};
    std::sort(data.begin(), data.end());
    std::cout << data.front() << '\n';
}
