#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
using int64 = long long;

vector< int64 > divisor(int64 n)
{
    vector< int64 > ret;
    for(int64 i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}
int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    ll ans = 0;
    rep(i,3001){
        rep(j,3001){
            int k = n - r * i  - j * g;
//            show(k);
            if(k>=0 and k%b==0)ans++;
        }
    }
    cout << ans << endl;
}
int main2(){
    int n;
    cin >> n;
    vector<string>s(n);
    rep(i,n)cin >> s[i];
    int ans = 0;
    rep(i,n){
        int k = (int) s[i].size();
        rep(j,k-1){
            if(s[i][j] == 'A' and s[i][j+1] == 'B')ans++;
        }
    }
    int a = 0, b = 0, c = 0, d = 0;
    rep(i,n){
        if(s[i][0] == 'A'){
            if(s[i].back() == 'A')a++;
            else b++;
        }else if(s[i][0] == 'B'){
            if(s[i].back() == 'A')c++;
            else d++;
        }
    }
    return 0;
}
