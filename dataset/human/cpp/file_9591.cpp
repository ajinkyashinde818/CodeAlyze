#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <sstream>
#include <iomanip>
using lint = long long;

int main()
{
    lint n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);

    std::vector<std::vector<lint>> a(n, std::vector<lint>(n, 0));
    std::vector<std::vector<lint>> b(m, std::vector<lint>(m, 0));

    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n; ++j)
        {
            if (s[j] == '.')
                a[i][j] = 1;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j)
        {
            if (s[j] == '.')
                b[i][j] = 1;
        }
    }

    for (int i = 0; i <= (n - m); ++i)
    {
        for (int j = 0; j <= (n - m); ++j)
        {
            lint ok = 1;
            for (int y = 0; y < m; ++y)
            {
                for (int x = 0; x < m; ++x)
                {
                    if (a[i + y][j + x] != b[y][x])
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok == 0)
                    break;
            }
            if (ok)
            {
                printf("Yes");
                return 0;
            }
        }
    }

    printf("No");
    return 0;
}
