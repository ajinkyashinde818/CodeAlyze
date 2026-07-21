#include <bits/stdc++.h>
using namespace std; 
const int maxn = 100500;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long ans = 0, r, g, b, n;
    cin >> r >> g >> b >> n;
    for(int i = 0 ; i <= n ; ++i)
        for(int j = 0 ; j <= n ; ++j){
            long long sm = i * r + j * g;
            if(sm > n || (n - sm) % b) continue;
            ans++;
        }
    cout << ans << '\n';
    return 0;

}
