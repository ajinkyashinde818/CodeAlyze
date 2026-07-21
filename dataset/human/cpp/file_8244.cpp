#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<long long> a(n);
    int i;
    for(i=0;i<n;i++)cin>>a.at(i);
    vector<long long> sum(n+1,0);
    for(i=1;i<=n;i++)sum.at(i)=sum.at(i-1)+a.at(i-1);
    long long ans=1e+15;
    long long kans;
    for(i=1;i<n;i++)
    {
        kans=abs(sum.at(i)-(sum.at(n)-sum.at(i)));
        ans=(kans<ans)?kans:ans;
    }
    cout<<ans<<endl;
}
