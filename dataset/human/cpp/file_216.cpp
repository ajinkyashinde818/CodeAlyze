#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <set>

using namespace std;
using ll = long long;
const int MOD = 1000000007;
const ll INF = 1LL << 60;

// LRUD
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
// const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
// const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<vector<int> > vvi;
vector<vector<vector<int> > > vvvi;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }


int main(int argc, char**argv){
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    ll ans = 0;
    for (int i = 0; i <= n / r; i++){
        for (int j = 0; j <= n / g; j++){
            int sum = r*i + g*j;
            if (n - sum >= 0 && (n - sum) % b == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
