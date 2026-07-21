#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    long long n;
    long long a[200009]={};
    long long s=0;
    long long m=0;
    long long ans=9999999999;
    
    cin >> n;
    
    for(int i=1; i<=n; i++){
        
        cin >> a[i];
        s += a[i];
        
    }
    
    for(int i=1; i<=n-1; i++){
        
        m += a[i];
        ans = min(ans, abs(s-m*2));
        
    }
    
    cout << ans << endl;
    
    return 0;
    
}
