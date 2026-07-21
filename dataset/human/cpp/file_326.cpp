#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }


int main(){
    ll R, G, B, N, ans = 0;
    cin >> R >> G >> B >> N;
    
    for(int i  = 0; i <= N; i++){
        for(int j = 0; j <= N - i * R; j++){
            if((N - (i * R + j * G)) / B >= 0 && (N - (i * R + j * G)) % B == 0){
                ans++;
            }
        }
    }

    cout << ans << endl;
}
