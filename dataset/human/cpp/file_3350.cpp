/*
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    long num = 0, sum = 0;
    int abs_min = std::abs(a[0]);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            num++;
        abs_min = std::min(abs_min, std::abs(a[i]));
        sum += std::abs(a[i]);
    }

    if (num % 2 == 0)
        std::cout << sum << std::endl;
    else
        std::cout << sum - abs_min * 2 << std::endl;
    return 0;
}
