#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
    詰まった時に、別の分野の問題として考え直す（これdpでは？、グラフとしてみればいいのでは？）
    多くの問題はパターンマッチだが、パターンに落とし込むまでが難しく、そのための訓練としてわからない問題をあれこれ色々な角度から考察してみるのではないか
*/

const ll mod = 1e9+7;

void chmod(ll &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

ll modpow(ll x, ll n){
    if(n == 0) return 1;

    ll res = modpow(x, n/2);
    if(n%2 == 0) return res*res%mod;
    else return res*res%mod*x%mod;
}

ll power(ll x, ll n){
    if(n == 0) return 1;

    ll res = power(x, n/2);
    if(n%2 == 0) return res*res;
    else return res*res*x;
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };

/* <--------------------------------------------> */

typedef tuple<ll, ll, ll> T;



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin >> n;
    string s; cin >> s;

    ll ans = 1;
    ll cord = 0;

    for(int i=0; i<2*n; ++i){
        if(s[i] == 'W'){
            if(cord%2 == 0){
                if(cord == 0) {
                    cout << 0 << endl;
                    return 0;
                }
                else{
                    ans *= cord;
                    chmod(ans);
                    --cord;
                    if(i == 2*n-1 && cord != 0){
                        cout << 0 << endl;
                        return 0;
                    }
                }
            }
            else{
                ++cord;
                if(i == 2*n-1){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
        else{
            if(cord%2 == 0){
                ++cord;
                if(i == 2*n-1){
                    cout << 0 << endl;
                    return 0;
                }
            }
            else{
                ans *= cord;
                chmod(ans);
                --cord;
                if(i == 2*n-1 && cord != 0){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    

    for(int i=1; i<=n; ++i){
        ans *= i;
        chmod(ans);
    }
    cout << ans << endl;

    return 0;
}
