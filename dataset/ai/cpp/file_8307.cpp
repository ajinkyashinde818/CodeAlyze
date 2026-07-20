#include <algorithm>
#include <vector>
#include <iostream>
int main()
{
    std::vector<int> data{63, 15, 6};
    std::sort(data.begin(), data.end());
    std::cout << data.front() << '\n';
}
