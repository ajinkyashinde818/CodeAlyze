#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, g, b, n;
    cin >> r >> g >> b >> n;

    long long int ans = 0;
    for(int i=0; i<=n/r; i++){
        for(int j=0; j<=n/g; j++){
            if(i * r + j * g > n) break;
            if((n - (i * r + j * g)) % b == 0) ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
