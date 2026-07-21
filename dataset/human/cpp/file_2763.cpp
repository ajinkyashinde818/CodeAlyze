#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x=0,a;
    cin>>n;
    long long ans=0;
    int m=INT_MAX;
    while(n--)
    {
        cin>>a;
        ans+=abs(a);
        m=min(m,abs(a));
        if(a<0)
        x++;
    }
    if(x&1)
    ans-=2*m;
    cout << ans ;
    return 0;
}
