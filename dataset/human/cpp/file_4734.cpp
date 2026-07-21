#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <climits>

using namespace std;

const int N = 3e5 + 5000;
int n, m, T, a[N];

int main()
{
#ifdef ONLINE_JUDGE
#else
    // freopen("r.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cout << m + max(10 - n, 0) * 100;
}
