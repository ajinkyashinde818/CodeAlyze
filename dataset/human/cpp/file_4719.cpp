#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,r;
    cin>>n>>r;
    if(n>9)
    {
        cout<<r<<endl;
    }
    else
    {
        cout<<r+(100*(10-n))<<endl;
    }
    return 0;
}
