#include <iostream>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;

    int K = 0;
    ll ans = 1;
    for(auto c : S){
        if((c == 'W' && K%2 == 0) || (c == 'B' && K%2 == 1)){
            ans *= K;
            ans %= mod;
            if ((--K) < 0)break;
        }else{
            K++;
        }
    }
    if(K != 0){
        cout << 0 << endl;
        return 0;
    }

    for(int i=1;i<=N;i++){
        ans *= i;
        ans %= mod;
    }
    cout << ans << endl;

}
