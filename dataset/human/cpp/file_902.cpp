#include<bits/stdc++.h>
using namespace std;




int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int r, g, b, n, ans = 0;
    cin >> r >> g >> b >> n;
    for(int i = 0; i * r <= n; i++){
        for(int j = 0; i * r + j * g <= n; j++){
            int k = n - (i * r + j * g);
            if(k % b == 0){
                ans += 1;
            }
        }
    }
    cout << ans;
}
