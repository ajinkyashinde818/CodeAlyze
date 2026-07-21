#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    int n,r;
    cin>>n>>r;
    if(n>=10){
        cout << r << endl;
        return 0;
    }
    int ans = r + 100 * (10 - n);
    cout << ans << endl;
    
}
