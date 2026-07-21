#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0)

// *start on @date: 2020-02-22 20:06

ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};

int main()
{
    IOS;
    int a, b;
    cin >> a >> b;
    if (a < 10)
    {
        int t = 100 * (10 - a);
        cout << b + t;
    }
    else
    {
        cout << b;
    }

    return 0;
}
