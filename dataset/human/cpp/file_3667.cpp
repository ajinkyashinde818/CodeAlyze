#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T, class C> void chmax(T& a, C b){ a>b?:a=b; }
template<class T, class C> void chmin(T& a, C b){ a<b?:a=b; }


int main(){
    int N;
    cin>>N;
    // vector<ll> a;
    ll a_;
    ll m=9223372036854775807, s=0;
    int n=0;
    rep(i, N){
        cin>>a_;
        if(a_<0){
            ++n;
        }
        m = min(m, abs(a_));
        s+=abs(a_);
        // a.push_back(a_);

    }
    if(n%2==1){
        s-=m*2;
    }
    cout<<s<<endl;

    return 0;

}
