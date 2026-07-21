#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int i = 0, j = 0, ans = 0;
    while (R * i <= N)
    {
        while (R * i + G * j <= N)
        {
            if ((N - (R * i + G * j)) % B == 0)
            {
                ans++;
            }
            j++;
        }
        j = 0;
        i++;
    }
    cout << ans << endl;
}
