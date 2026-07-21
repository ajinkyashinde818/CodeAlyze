#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr long double EPS = 1e-15;
const long double PI = acos(-1);
constexpr int inf = 2e9;
constexpr ll INF = 2e18;
constexpr ll MOD = 1e9+7;
constexpr ll MOD1 = 998244353;
typedef pair<ll,ll> P;
//#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

int used[200010];
bool ok[200010];

void solve() {
    int n,k;
    cin >> n >> k;
    int a[k];
    REP(i,k) {
        cin >> a[i];
        a[i]--;
        used[a[i]]++;
        ok[a[i]] = 1;
    }
    reverse(a,a+k);
    REP(i,k) {
        if (used[a[i]] != 0) {
            cout << a[i] + 1 << endl;
            used[a[i]] = 0;
        }
    }
    REP(i,n) {
        if (!ok[i]) cout << i+1 << endl;
    }
}

int main(int argc, char *argv[]){
    // /* Regular */
    // int case_num = 1;
    // if (argc > 1 && stoi(argv[1])) cin >> case_num;
    // REP(case_no, case_num) {
    //   cerr << endl << "case " << case_no + 1 << endl;
    //   solve();
    // }
    /* AOJ */
    solve();
    return 0;
}
