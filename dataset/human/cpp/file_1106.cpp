#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <iterator>
#include <queue>
#include <cmath>
#include <cassert>

typedef long long ll;
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)

int main ()
{
    ll R,G,B,N;
    cin >> R >> G >> B >> N;

    ll ans = 0;
    for (ll a = 0; a <= 3000; a++) {
        for (ll b = 0; b <= 3000; b++) {
            ll leftc = N - a * R - b * G;
            if (leftc < 0) continue;
            if (leftc % B == 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
