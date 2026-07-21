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
#include <cstring>
using namespace std;

using ll = long long;
using P = pair<int, int>;
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
    int zero = 0;
    vector<int> positive, negative;
    int mine = INF;
    for(int i = 0; i < N; ++i){
        int A;
        cin >> A;
        if(A == 0)  ++zero;
        else if(A > 0)  positive.emplace_back(A);
        else    negative.emplace_back(-A);
        chmin(mine, abs(A));
    }
    int np = positive.size(), nn = negative.size();
    ll ans = accumulate(positive.begin(), positive.end(), 0LL);
    ans += accumulate(negative.begin(), negative.end(), 0LL);
    if((nn & 1) && !zero)   ans -= mine * 2;
    cout << ans << endl;
}
