#include <bits/stdc++.h>
 
using namespace std;
 
// typedef
typedef long long ll;
typedef long double ldbl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
 
// container util
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
// repetition
#define FOR(i,m,n) for (ll (i) = ((ll) m); (i) < ((ll) n); ++(i))
#define RFOR(i,m,n) for (ll (i) = ((ll) (m)-1); (i) >= ((ll) n); --(i))
#define REP(i,n) FOR(i,0,n)
 
// i/o
#define TFOUT(b,t,f) cout << ((b)? (t) : (f)) << endl
 
// constant
const double PI  = acos(-1.0);
const int    MOD = (int)(1e9 + 7);
// DO NOT set INFTY_XXXs constants. They may bring some BUG! Use MAX_XXXs in climit instead.
 
// clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
// debug
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl


template<typename T>
inline vector<T> cin_vector(const size_t n) {
     vector<T> vec;
    vec.reserve(n);
    REP(i, n) {
        T element; cin >> element;
        vec.push_back(element);
    }
    return vec;
}

template<typename T>
inline vector< vector<T> > cin_matrix(const size_t m, const size_t n) {
    vector< vector<T> > matrix;
    matrix.reserve(m);
    REP(i, m) {
        vector<T> vec = cin_vector<T>(n);
        matrix.push_back(vec);
    }
    return matrix;
}

template<typename T>
inline void cout_vector(const vector<T>& vec) {
    REP(i, SZ(vec)-1) {
       cout << vec[i] << ' ';
    }
    cout << vec[SZ(vec)-1] << endl;
}

template<typename T>
inline void cout_matrix(vector< vector<T> > matrix) {
    for(const vector<T>& vec : matrix) {
         cout_vector<T>(vec);
    }
}


int main() {
    int n, r; cin >> n >> r;
    int ans = (n >= 10 ? r : (r + 100*(10 - n)));
    cout << ans << endl;
    return 0;
}
