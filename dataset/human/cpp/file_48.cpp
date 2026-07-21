#include <iostream>
#include <algorithm>
#include <cstdio>
#include <regex>
#include <cmath>
#include <vector>
#include <queue>
#include <functional>
#include <numeric>
#include <iomanip>
#include <stack>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

int main () {
    ll R, G, B, N;
    cin >> R >> G >> B >> N;
    ll ans;
    for (int r = 0; r <= N; r++)
    {
        for (int g = 0; g <= N; g++)
        {
            ll b = N - R * r - G * g;
            if(b >= 0 && b % B == 0) {
                ans++;
            }
        }
        
    }
    cout << ans << endl;
}
