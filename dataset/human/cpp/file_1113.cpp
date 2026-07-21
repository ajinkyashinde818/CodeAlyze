#include <bits/stdc++.h>

using namespace std;
int main()
{
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    long long ans=0;
    for(int i=0;i<=n/r;i++){
        int temp=n-i*r;
        for(int j=0;j<=temp/g;j++){
            int temp2=temp-j*g;
            if(temp2%b==0){
                ans++;
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<ans;
}
