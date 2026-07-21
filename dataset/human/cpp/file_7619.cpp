#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

#define CIN(T, x) T x; cin >> x;
#define CINS(T, x, N) vector<T> x(N); for(int i = 0; i < (N); i++) { cin >> x[i]; }
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << " "; } cout << "\n";
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << "\n";


int main() {

    CIN(int, N);
    CINS(int, a, N)
    ll sum = 0;

    for (int i = 0; i < N; i++) {
        sum += a[i];
    }

    ll sum1 = a[0], sum2 = sum - a[0];
    ll MIN = fabs(sum1-sum2);

    for (int i = 1; i < N-1; i++) {
        sum1 += a[i];
        sum2 -= a[i];
        MIN = min(MIN, (ll)fabs(sum1 - sum2));
    }

    cout << MIN << "\n";
    return 0;
}
