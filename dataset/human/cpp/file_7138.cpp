#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>

using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("Yes")
#define p_no() p("No")

const ll mod = 1e9 + 7;
const ll inf = 1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    int N;
    cin >> N;

    vector<ll> A(N);
    FOR(i, 0, N){
        cin >> A.at(i);
    }

    vector<ll> AC(N);
    AC[0] = A[0];
    FOR(i, 1, N){
        AC[i] = AC[i-1] + A[i];
    }

    ll min_diff = abs(AC[N-2] - A[N-1]);
    FOR(i, 0, N-1){
        ll x = AC[i];
        ll y = AC[N-1] - AC[i];
        ll diff = abs(x-y);
        min_diff = min(min_diff, diff);
    }

    p(min_diff);
    
    return 0;
}
