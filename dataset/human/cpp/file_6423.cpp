#include <iostream>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

char S[200000];
int t[200000];

int main(){
    int N;
    cin >> N;
    t[0] = 1;
    for(int i = 0; i < 2*N; i++){
        cin >> S[i];
        if(i >= 1){
            if(S[i] == S[i-1]) t[i] = -t[i-1];
            else t[i] = t[i-1];
        }
    }
    if(S[0] == 'W' || S[2*N-1] == 'W') {
        cout << 0 << endl;
        return 0;
    }
    ll cnt = 0;
    ll ans = 1;
    for(ll i = 1; i <= N; i++){
        ans *= i;
        ans %= MOD;
    }
    for(int i = 0; i < 2*N; i++){
        if(t[i] == -1){
            ans *= cnt;
            ans %= MOD;
        }
        cnt += t[i];
    }
    if(cnt != 0){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }
}
