#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
#include <complex>
using namespace std;

using ll = long long;
using ull = uint64_t;
using P = pair<int, int>;
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

template<class T>
inline bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> dp(210, vector<int>(210, -1));
    auto MemoRec = [&](auto&& self, int w, int b) -> int {
        if(dp[w][b] != -1)  return dp[w][b];
        set<int> Grundy;
        if(w > 0)   Grundy.emplace(self(self, w - 1, b));
        if(b > 0)   Grundy.emplace(self(self, w + 1, b - 1));
        for(int i = 1; i <= w; ++i){
            if(b - i < 0)   break;
            Grundy.emplace(self(self, w, b - i));
        }
        int res = 0;
        while(Grundy.count(res))    ++res;
        return dp[w][b] = res;
    };
    int Nim = 0;
    for(int i = 0; i < N; ++i){
        int w, b;
        cin >> w >> b;
        Nim ^= MemoRec(MemoRec, w, b);
    }
    cout << (Nim == 0) << endl;
}
