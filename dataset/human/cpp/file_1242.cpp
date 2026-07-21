#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef pair<LL, LL> PII;
typedef vector<string> VS;
inline LL toInt(string s) {LL v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
#define PB push_back
#define MP make_pair
#define SZ(a) LL((a).size())
#define EACH(x,c) for(auto x: (c))
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define ALL(c) (c).begin(), (c).end()
#define REVERSE(c) reverse(ALL(c))
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define STABLE_SORT(c) stable_sort(ALL(c))
#define STABLE_RSORT(c) stable_sort((c).rbegin(),(c).rend())
#define UNIQUE(c) SORT(c); (c).erase(unique(ALL(c)), (c).end());
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
const double INF = 1e7;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define dump(x)  cerr << #x << " = " << (x) << endl;


int main() {
	LL R, G, B, N;
    cin >> R >> G >> B >> N;
    LL ans = 0;
    /*LL r = N / R;
    if (N % R == 0) {
        r++;
        }*/
    REP(i, N / R + 1) {
        REP(j, (N - i * R) / G + 1) {
            /*dump(i);
              dump(j);*/
            if ((N - i * R - j * G) % B == 0) {
                //cout << "OK\n";
                ans++;
            }
        }
    }
	cout << ans << endl;
    return 0;
}
