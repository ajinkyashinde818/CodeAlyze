#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream& operator >> (istream& istr, vector<T>& v){
    for(T& x: v) istr >> x;
    return istr;
}

template<typename T, typename U>
istream& operator >> (istream& istr, pair<T,U>& p){
    istr >> p.first >> p.second;
    return istr;
}

template<typename T>
ostream& operator << (ostream& ostr, vector<T>& v){
    if(!v.empty()){
        ostr << v.front();
        for(auto itr = ++v.begin(); itr != v.end(); itr++)
            // ostr << *itr;
            ostr << " " << *itr;
    }
    return ostr;
}

template<typename T, typename U>
ostream& operator << (ostream& ostr, pair<T,U>& p){
    // ostr << p.first << p.second;
    ostr << p.first << ", " << p.second;
    return ostr;
}

template<typename T>
ostream& operator << (ostream& ostr, vector<vector<T>>& vv){
    if(!vv.empty()){
        ostr << vv.front();
        for(auto itr = ++vv.begin(); itr != vv.end(); itr++)
            ostr << endl << *itr;
    }
    return ostr;
}

template<typename T, typename U>
ostream& operator << (ostream& ostr, vector<pair<T,U>>& vp){
    if(!vp.empty()){
        ostr << vp.front();
        for(auto itr = ++vp.begin(); itr != vp.end(); itr++)
            ostr << endl << *itr;
    }
    return ostr;
}

typedef long long ll;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<double> vd;
// vll x(n); x[i]=a;
typedef vector<vll> vvll;
typedef vector<vc> vvc;
typedef vector<vd> vvd;
// vvll x(m,vi(n)); x[i][j]=a;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
typedef vector<pll> vpll;
typedef vector<pd> vpd;
// vpll x(n); x[i]={a,b}; x[i].first/second;

#define PI 3.1415926535897932
#define EPS 1e-12
#define INF (ll)1e+12
#define REP(i,n) for(ll i=0; i<(n); i++)
#define RREP(i,n) for(ll i=(n)-1; i>=0; i--)
#define FOR(i,a,b) for(ll i=(a); i<(b); i++)
#define FORR(i,a,b) for(ll i=(b)-1; i>=(a); i--)
#define fix(x) cout << fixed << setprecision(x)
#define dump(x) cout << #x << " = " << (x) << endl
#define all(x) (x).begin(),(x).end()

template<typename T> T sum(vector<T> &v) {return accumulate(all(v), (T)0LL);}
template<typename T> void sort(vector<T> &v){sort(all(v));}
template<typename T> void rsort(vector<T> &v){sort(all(v),greater<T>());}

int main(){
    ll n, r = 0;
    cin >> n >> r;
    if(n>=10) cout << r << endl;
    else cout << r+100*(10-n) << endl;
    return 0;
}
