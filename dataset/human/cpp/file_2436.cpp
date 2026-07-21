#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100010],f[100010][2]={};
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	f[1][0]=-a[1];
	f[1][1]=a[1];
    for (int i=2;i<=n;i++)
	{
	    f[i][0]=max(f[i-1][0]+a[i],f[i-1][1]-a[i]);
		f[i][1]=max(f[i-1][0]-a[i],f[i-1][1]+a[i]);
    }
    cout<<f[n][1];
}
