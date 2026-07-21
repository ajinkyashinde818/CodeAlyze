#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    int ans=0;
    for(int i=0;i<=n/r;i++){
        for(int k=0;k<=n/g;k++){
            if((n-(i*r+k*g))%b==0 && n-(i*r+k*g)>=0) ans++;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
