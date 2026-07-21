#include<bits/stdc++.h>
using namespace std;

int r,g,b,n,ans,x;

int main(){
    cin>>r>>g>>b>>n;
    x=__gcd(g,b);
    for(int t=n; t>=0; t-=r){
        if(t%x) continue;
        for(int s=t; s>=0; s-=g){
            if(s%b) continue;
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}
