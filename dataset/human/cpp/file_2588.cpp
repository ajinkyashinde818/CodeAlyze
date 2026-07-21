#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
#define what(x) cerr << #x << " is " << x << endl;
const ll INF = 1LL << 60;

int main() {
    ll N;
    cin >> N;
    vl A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vl A2 = A;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] < 0) {
            A[i] *= -1LL;
            A[i + 1] *= -1LL;
        }
    }
    bool ok = A[N - 1] >= 0;
    ll ret = 0;
    ll mi = INF;
    for (int i = 0; i < N; ++i) {
        ll ab = abs(A[i]);
        ret += ab;
        mi = min(mi, ab);
    }
    cout << (ok ? ret : ret - 2 * mi) << endl;
    return 0;
}
