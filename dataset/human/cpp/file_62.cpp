#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <bitset>
#include <queue>
#include <unordered_set>

using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
#define rep(i, n) for(int i = 0;i < n;i++)
const int INF = 1LL << 30;

int MOD = 1000000007;

int main(){
    std::ios_base::sync_with_stdio(false);

    int R,G,B,N; cin >> R >> G >> B >> N;

    ll cnt=0LL;

    rep(r, N+1){
        rep(g, N+1){

            int rem = N-r*R-g*G;

            if(rem>=0 && rem%B==0) cnt++;

        }

    }

    cout << cnt << endl;
    

    return 0;
}
