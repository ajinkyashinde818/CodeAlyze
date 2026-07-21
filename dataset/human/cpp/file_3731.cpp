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

    std::vector<lint> a_l(n);

    lint minus_num = 0;
    lint min = 1e9 + 1;
    lint sum = 0;

    for (int i = 0; i < n; ++i)
    {
        lint a;
        scanf("%lld", &a);
        if (a < 0)
        {
            minus_num++;
            a *= -1;
        }
        sum += a;
        min = std::min(min, a);
    }

    if (minus_num % 2 == 0)
    {
        printf("%lld", sum);
    }
    else
    {
        printf("%lld", sum - min * 2);
    }

    return 0;
}
