#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int main(){
    int N; cin >> N;
    vector<ll> a(N), cum(N,0);

    for(int i=0; i<N; i++){
        cin >> a[i];
        if(i == 0) cum[i] = a[i];
        else cum[i] = cum[i-1]+a[i];
    }

    ll ans = 1LL<<59;
    for(int i=0; i<N-1; i++){
        chmin(ans, abs(cum[i] - cum[N-1]+cum[i]));
    }

    cout << ans << endl;
}
