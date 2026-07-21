#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n);i>=0;--i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl;


typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);


    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;
    REP(r,3001)REP(g,3001){
        if (N-r*R-g*G < 0 ) continue;
        if ((N-r*R-g*G) % B == 0) ans++;
    }

    cout << ans << endl;

    return 0;
}
