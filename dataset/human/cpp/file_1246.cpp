/*
diverta 2019 Programming Contest A
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

int main()
{
    int R, G, B, n, ans = 0;
    std::cin >> R >> G >> B >> n;
    int r, g, b;
    for (r = 0; r <= n; r += R)
    {
        for (g = 0; r + g <= n; g += G)
        {
            if ((n - r - g) % B == 0)
                ans++;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
