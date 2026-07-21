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
    ll N, C; cin >> N >> C;
    vector<ll> x(N+2, 0), v(N+2, 0);
    for(int i=1; i<=N; ++i) cin >> x[i] >> v[i];
    x[N+1] = C;
    ll ans = 0;

    vector<ll> cumv(N+2, 0), f1(N+1, 0), g1(N+1, 0), f2(N+1, 0), g2(N+1, 0);
    for(int i=1; i<=N+1; ++i) cumv[i] = cumv[i-1] + v[i];


    for(int i=1; i<=N; ++i){
        f1[i] = cumv[i] - x[i];
        g1[i] = max(g1[i-1], f1[i]);
        f2[i] = cumv[i] - 2*x[i];
        g2[i] = max(g2[i-1], f2[i]);
    }

    for(int b=1; b<=N+1; ++b){
        // in case of walking OA+2OB
        chmax(ans, cumv[N]-cumv[b-1]-2*(C-x[b])+g1[b-1]);

        // in case of walking 2OA+OB
        chmax(ans, cumv[N]-cumv[b-1]-(C-x[b])+g2[b-1]);
    }

    cout << ans << endl;
    return 0;
}
