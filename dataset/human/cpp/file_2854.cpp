#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

    ll N;
    cin >> N;
    vector<ll> A(N);
    ll count = 0;
    ll sum = 0;
    ll minarg = 0;
    REP(i, N) {
        cin >> A[i];
        sum += abs(A[i]);
        if (A[i] < 0) count++;
        if (abs(A[minarg]) > abs(A[i])) minarg = i;
    }
    ll ans;
    if (count % 2 == 0) ans = sum;
    else{
        ans = sum - 2 * abs(A[minarg]);
    }
    cout << ans << endl;

    return 0;
}
