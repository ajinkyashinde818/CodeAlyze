#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#include <set>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    ll R,G,B,N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    for (int i = 0; i <= N; ++i) {
        for (int k = 0; k <= N; ++k) {
            //現在の個数
            int num = R*i + G*k;
            //残りの必要数
            int p = N - num;
            if (p == 0) {
                ans++;
            } else if (p > 0 && p % B == 0)  {
                ans++;
            }
        }
    }
    cout << ans << endl;


    return 0;
}
