#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vi2 = vector<vector<int>>;
using vb = vector<bool>;
using vb2 = vector<vector<bool>>;
using vc = vector<char>;
using vc2 = vector<vector<char>>;
using vs = vector<string>;
using si = set<int>;
using vs2 = vector<vector<string>>;
using pii = pair<int, int>;
using mii = map<int, int>;
const int INF = 1e9;
const ll LINF = 1e18;
#define MP(a,b) make_pair((a),(b))
#define MT(...) make_tuple(__VA_ARGS__)
#define sz(x) (int)(x).size()
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
 
#define ALL(x) (x).begin(),(x).end()
#define SORT(v) sort(ALL(v));
#define IN(type,a) type a;cin >> a;
#define VIN(type,a,n) vector<type> a(n);cin >> a;
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl;
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl;
#define COUT(x) cout << (x) << endl;
#define DCOUT(x,n) cout << fixed << setprecision(n) << (x) << endl;
#define ENDL cout << endl;
#define DB(s,x) cout << (s) << " : " << x << endl;

#define HOGE COUT("HOGE")

template<typename T>inline istream& operator>>(istream&i,vector<T>&v)
{REP(j,sz(v))i>>v[j];return i;}

int main() {
    IN(ll, n);
    VIN(ll, a, n);
    ll neg = 0;
    ll sum = 0;
    ll minab = INF;
    REP(i, n){
        if (a[i]<0) {
            neg++;
        }
        sum += abs(a[i]);
        minab = min(minab, abs(a[i]));
    }
    if (neg%2==0) {
        COUT(sum);
    }else {
        COUT(sum-2*minab);
    }
}
