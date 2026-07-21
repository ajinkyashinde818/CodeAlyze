#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const N=1e3;
ll INF=0x3f3f3f3f;
int main()
{
    ll n,r;
    cin>>n>>r;
    if(n>=10)
        cout<<r<<endl;
    else
        cout<<r+1000-n*100<<endl;
    return 0;
}
