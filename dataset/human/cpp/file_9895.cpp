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
#include <set>
#include <deque>
#include <numeric>
using lint = long long;

int main()
{
    lint n;
    scanf("%lld", &n);

    std::string s;
    std::cin >> s;

    std::map<char, lint> m;

    for (int i = 0; i < n; ++i)
    {
        if (m.find(s[i]) == m.end())
            m[s[i]] = 1;
        else
            m[s[i]]++;
    }

    lint ans = 1;
    lint mod = 1e9 + 7;

    for (auto c = m.begin(); c != m.end(); c++)
    {
        ans = ans * (c->second + 1) % mod;
    }

    printf("%lld", ans - 1);
    return 0;
}
