#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime> 
#include <memory.h>
#include <assert.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1e9 + 1;
const ll LLINF = 1e18 + 1;

int main(){
    int N;
    cin >> N;
    int cnt = 0;
    vector<ll> A;
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if (a < 0) cnt++;
        A.push_back(abs(a));
    }

    sort(A.begin(), A.end());

    ll ans = (cnt%2 == 0) ? A[0] : -A[0];
    for(int i = 1; i < N; i++) {
        ans += A[i];
    }    

    cout << ans << endl;

    return 0;
}
