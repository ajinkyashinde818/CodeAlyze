//{{{
#include<algorithm>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<random>
#include<set>
#include<sstream>
#include<sys/time.h>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printw) FUNC(printwe) FUNC(printb) FUNC(printbe) FUNC(printd) FUNC(printde) FUNC(printdu);
#endif
template <class S, class T>
istream& operator >> (istream& in, pair<S, T>& p){ return in >> p.first >> p.second; }
template <class T>
istream& operator >> (istream& in, vector<T>& v){ for(auto& e : v){ in >> e; } return in; }
//}}}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    ll ans = 0;
    for(int i = 0; i * r <= n; i++){
        for(int j = 0; j * g <= n; j++){
            int k = n - i * r - j * g;
            if(k % b || k < 0){ continue; }
            printde(i, j, k / b);
            ans++;
        }
    }
    cout << ans << '\n';
}
