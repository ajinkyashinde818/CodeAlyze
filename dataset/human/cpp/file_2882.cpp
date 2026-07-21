#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>

#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;

int main(void)
{
    int n;
    cin >> n;
    long long a[n];
    REP(i, n)
    {
        cin >> a[i];
    }
    int cnt = 0;
    long long sum = 0;
    long long minv = 1e10;
    REP(i, n)
    {
        sum += abs(a[i]);
        if (abs(a[i]) < minv)
        {
            minv = abs(a[i]);
        }
        if (a[i] < 0)
        {
            cnt++;
        }
    }
    if (cnt % 2 == 0)
    {
        cout << sum << endl;
    }
    else
    {
        cout << sum - 2 * minv << endl;
    }
}
