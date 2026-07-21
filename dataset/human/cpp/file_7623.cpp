#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    long long a[1000000],s[1000000];
    s[0]=0;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        /* code */
        s[i]=s[i-1]+a[i-1];
    }
    long long ans=0,ans2=1000000000000000000LL;
    for (int i = 1; i < n; i++)
    {
        /* code */
        ans=abs(s[i]-(s[n]-s[i]));
        ans2=min(ans,ans2);
    }
    cout<<ans2<<endl;
    
}
