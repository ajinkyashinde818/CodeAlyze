#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int main ()
{
    int N; cin >> N;
    vector < ll > A(N);
    REP(i,N) cin >> A[i];

    int cnt = 0;
    int zero = 0;
    ll sum = 0;
    REP(i,A.size()) {
        if (A[i] >= 0) sum += A[i];
        else sum -= A[i];
        if (A[i] == 0) {
            zero++;
        }
        if (A[i] < 0) {
            cnt++;
        }
    }

    if (zero > 0) {
        cout << sum << endl;
        return 0;
    }

    if (cnt % 2 == 0) {
        cout << sum << endl;
        return 0;
    }

    ll ans = 0;
    REP(i,A.size()) {
        if (A[i] < 0) {
            ans = max(ans, sum + 2LL * A[i]);
        } else {
            ans = max(ans, sum - 2LL * A[i]);
        }
    }

    cout << ans << endl;

    return 0;
}
