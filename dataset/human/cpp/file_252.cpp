#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

#include <utility>
#include <list>

#include <cmath>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <complex>
#include <climits>
#include <functional>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back

#define debug(x) cerr << #x << " = " << x << " "
int main()
{
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for (int i = 0; i * r <= n; ++i)
        for (int j = 0; j * g <= n; ++j)
        {
            int left = n - i * r - j * g;
            ans += left >= 0 && left % b == 0;
        }
    cout << ans << endl;
}
