#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cmath>
#include <map>

int main()
{
    int R, G, B, N;
    std::cin >> R >> G >> B >> N;

    int cnt = 0;
    for (int r = 0; r < N / R + 1; r++)
    {
        int rR = r * R;
        for (int g = 0; g < (N - rR) / G + 1; g++)
        {
            if ((N - rR - g * G) % B == 0)cnt++;
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}
