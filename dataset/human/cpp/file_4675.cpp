//include
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std;
//------------------------------------------
//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<long long> VL;
typedef vector<VI> VVI;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef vector<VL> VVL;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef pair<int, string> PIS;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
//------------------------------------------
//comparison
#define C_MAX(a, b) ((a)>(b)?(a):(b))
#define C_MIN(a, b) ((a)<(b)?(a):(b))
#define C_ABS(a, b) ((a)<(b)?(b)-(a):(a)-(b))
//------------------------------------------
//container util
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define REVERSE(c) reverse((c).begin(), (c).end())
#define SUMI(obj) accumulate((obj).begin(), (obj).end(), 0)
#define SUMD(obj) accumulate((obj).begin(), (obj).end(), 0.)
#define SUML(obj) accumulate((obj).begin(), (obj).end(), 0ll)
#define UB(obj, n) upper_bound((obj).begin(), (obj).end(), n)
#define LB(obj, n) lower_bound((obj).begin(), (obj).end(), n)
#define BS(v, n) binary_search(ALL(v), (n))
#define PB push_back
#define MP make_pair
//------------------------------------------
//repetition
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n)  FOR(i,0,n)
#define RREP(i, n) for(int i = n-1;i >= 0;i--)
#define FORL(i, a, b) for(ll i=ll(a);i<ll(b);++i)
#define RFORL(i, a, b) for(ll i=ll(b)-1;i>=ll(a);--i)
#define REPL(i, n) for(ll i=0;i<ll(n);++i)
#define RREPL(i, n) for(ll i=ll(n)-1;i>=0;--i)
#define FOREACH(x, v) for(auto &(x) : (v))
#define FORITER(x, v) for(auto (x) = (v).begin(); (x) != (v).end(); ++(x))
//------------------------------------------
//input output
#define GL(s) getline(cin, (s))
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define IN(...) GET_MACRO(__VA_ARGS__, IN3, IN2, IN1)(__VA_ARGS__)
#define IN1(n) std::cin>>(n);
#define IN2(n,m) std::cin>>(n)>>(m);
#define IN3(n,m,l) std::cin>>(n)>>(m)>>(l);
#define OUT(d) std::cout<<(d);
#define OUT_L(d) std::cout<<(d)<<endl;
#define FOUT(n, d) std::cout<<std::fixed<<std::setprecision(n)<<(d);
#define EL() std::cout << "\n";
//------------------------------------------
//constant
#define MOD 1000000007
//------------------------------------------

//数値・文字列
inline int toInt(string s) {
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}
inline ll toLongLong(string s) {
    ll v;
    istringstream sin(s);
    sin >> v;
    return v;
}
template<class T>
inline string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}
inline VC toVC(string s) {
    VC data(s.begin(), s.end());
    return data;
}
//------------------------------------------
//extended permutation combination
// possible implementation introduced at http://en.cppreference.com/w/cpp/algorithm/rotate with slight modification to handle parted ranges
template<typename FI>
void parted_rotate(FI first1, FI last1, FI first2, FI last2){
 if(first1 == last1 || first2 == last2) return;
 FI next = first2;
 while (first1 != next) {
  std::iter_swap(first1++, next++);
  if(first1 == last1) first1 = first2;
  if (next == last2) {
   next = first2;
  } else if (first1 == first2) {
   first2 = next;
  }
 }
}
template<typename BI>
bool next_combination_imp(BI first1, BI last1, BI first2, BI last2){
 if(first1 == last1 || first2 == last2) return false;
 auto target = last1; --target;
 auto last_elem = last2; --last_elem;
 // find right-most incrementable element: target
 while(target != first1 && !(*target < *last_elem)) --target;
 if(target == first1 && !(*target < *last_elem)) {
  parted_rotate(first1, last1, first2, last2);
  return false;
 }
 // find the next value to be incremented: *next
 auto next = first2;
 while(!(*target < *next)) ++next;
 std::iter_swap(target++, next++);
 parted_rotate(target, last1, next, last2);
 return true;
}
// INVARIANT: is_sorted(first, mid) && is_sorted(mid, last)
template<typename BI>
inline bool next_combination(BI first, BI mid, BI last){
 return next_combination_imp(first, mid, mid, last);
}
// INVARIANT: is_sorted(first, mid) && is_sorted(mid, last)
template<typename BI>
inline bool prev_combination(BI first, BI mid, BI last){
 return next_combination_imp(mid, last, first, mid);
}
//------------------------------------------
//other functions
//------------------------------------------
inline ll mypow(int k, int n){
    ll ans = 1;
    REP(i,n){
        ans *= k;
    }
    return ans;
}
//最大公約数
template<class T>
inline T GCD(const T x, const T y) {
    if (x < 0)return GCD(-x, y);
    if (y < 0)return GCD(x, -y);
    return (!y) ? x : GCD(y, x % y);
}

//最小公倍数
template<class T>
inline T LCM(const T x, const T y) {
    if (x < 0)return LCM(-x, y);
    if (y < 0)return LCM(x, -y);
    return x * (y / GCD(x, y));
}
//-----------------------------------------


//main code--------------------------------
void _main(){ 
    ll n,r;IN(n,r);
    ll out ;
    if(n>=10) out = r;
    else {
        out = r+100*(10-n);
    }
    OUT_L(out);
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
