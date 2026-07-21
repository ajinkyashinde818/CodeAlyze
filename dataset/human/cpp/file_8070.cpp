#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(int i = 0; i <N; i++) cin >> A[i];
    ll left[N], right[N]; // index iまでの和

    left[0] = A[0], right[N-1] = A[N-1];
    for(int i = 1; i < N; i++){
        left[i] = left[i-1] + A[i];
    }
    ll sum = left[N-1];
    ll ans = 1000000000000000000LL;
    for(int i = 0; i < N - 1; i++){
        ans = min(ans, abs(2 * left[i] - sum));
    }
    /*
    for(int i = N - 2; i >= 0; i--){
        right[i] = right[i+1] + A[i];
    }
    //for(int i = 0; i < N; i++) cout << right[i] << endl;
    ll minsum = 1e18;
    for(int i = 1; i < N; i++){
        minsum = min(minsum, llabs(left[i-1] - right[i]));
    }*/
    cout << ans << endl;
}
