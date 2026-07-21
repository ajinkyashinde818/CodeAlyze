#include <bits/stdc++.h>
using namespace std;

long long a[100005];
long long n,minv=1e9+7,total=0;

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (abs(a[i])<minv)  minv=abs(a[i]);
		total+=abs(a[i]);
	}
	for (int i=1;i<=n-1;i++)
	{
		if (a[i]<0)
		{
			a[i]=-a[i];
			a[i+1]=-a[i+1];
		}
	}
	if (a[n]<0)  cout<<total-minv*2<<endl;
	else cout<<total<<endl;
	return 0;
}
