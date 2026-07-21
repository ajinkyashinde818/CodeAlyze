#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <algorithm>
#include <numeric>
#include <limits>
#include <string>
#include <regex>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int n;
    long long a[100000];
    long long min_abs = 1000000000;
    long long ans = 0;
    int nsign = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        min_abs = min(min_abs, abs(a[i]));
        ans += abs(a[i]);
        if (a[i] < 0) nsign++;
    }
    if (nsign % 2 == 1) ans -= 2 * min_abs;
    cout << ans << endl;

    return 0;
}
