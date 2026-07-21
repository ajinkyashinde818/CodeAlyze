#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <chrono>
#include <queue>
#include <functional>

using namespace std;

typedef long long ll;

int dp[64][100+1];

int main() {
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    int N; 
    cin >> N;
    int fc = 0;
    ll abssum = 0;
    ll maxf = 1000000;
    for (int i = 0; i < N; ++i) {
        ll t;
        cin >> t;
        abssum += abs(t);
        if (t < 0) {
            ++fc;
        }
        maxf = min(maxf, abs(t));
    }

    if (fc % 2 == 0) {
        cout << abssum << std::endl;
    }
    else cout << (abssum - 2 * maxf) << std::endl;

    return 0;
}
