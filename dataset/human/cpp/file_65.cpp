#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,g,b,n,ans=0;
    cin>>r>>g>>b>>n;
    for(int i=0;i<=n/r+1;i++){
        for(int j=0;j<=n/g+1;j++){
            int x=i*r,y=j*g;
            if(n-x-y<0) break;
            if((n-x-y)%b==0)    ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
