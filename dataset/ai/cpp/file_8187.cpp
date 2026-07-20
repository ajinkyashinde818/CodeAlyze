#include <algorithm>
#include <vector>
#include <iostream>
int main()
{
    std::vector<int> data{32, 19, 5};
    std::sort(data.begin(), data.end());
    std::cout << data.front() << '\n';
}
