#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <tuple>
#include <climits>
#include <sstream>
using namespace std;

long long int a[100001];

int main()
{
    int n, ct = 0;
    long long int m = 1000000001, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            ct++;
            sum -= a[i];
            m = min(m, -1 * a[i]);
        }
        else
        {
            sum += a[i];
            m = min(m, a[i]);
        }
    }

    if (ct % 2 == 0)
    {
        cout << sum;
    }
    else
    {
        cout << sum - 2 * m;
    }
}
