#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<ll> Ai(N);
    int minus = 0;
    for (int i=0;i<N;i++){
        cin >> Ai[i];
        if (Ai[i] < 0) {
            minus++;
            Ai[i] = - Ai[i];
        }
    }
    // マイナスが奇数個のときはマイナスが１か所残る
    // マイナスが偶数個のときはマイナスを全部消せる
    sort(Ai.begin(),Ai.end());
    ll ans = 0;
    for (int i=0;i<N;i++){
        ans += Ai[i];
    }
    if (minus % 2 == 1){
        ans -= Ai[0]*2;
    }

    cout << ans << endl;
}
