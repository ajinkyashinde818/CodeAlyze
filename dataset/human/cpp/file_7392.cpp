#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <utility>
#include <set>
#include <map>
#include <tuple> 
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
using namespace  std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(long long (i)=0, i_bound = (long long)(n); (i)<i_bound; ++i)
#define FOR(i, a, b) for(long long (i)=(a); (i)<(b); ++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
const long long MOD = static_cast<long long>(1e9) + 7LL;
const long long INF = 1234567891234567890LL;
int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    int N; 
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    vector<ll> C(N+1);
    vector<ll> D(N+1);
    REP(i, N) {
        C[i+1] = A[i] + C[i];
        D[i+1] = A[N-1-i] + D[i];
    }
    ll res = INF;
    //cout << C << endl;
    //cout << D << endl;
    FOR(i, 1, N){
        res = min(res, abs(C[i] - D[N-i]));
    }
    cout << res << endl;
    return 0;
}
