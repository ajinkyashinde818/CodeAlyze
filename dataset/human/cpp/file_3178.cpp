#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500010],sum,c,mm=999999999999999;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=abs(a[i]);
		if(a[i]<0)
			c++;
		mm=min(mm,abs(a[i]));
	}
	//cout<<sum<<endl<<c<<endl<<mm;
	if(c%2==0)
		cout<<sum;
	else
		cout<<sum-2*mm;
	return 0;
}
