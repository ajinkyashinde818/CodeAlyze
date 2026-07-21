#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long n,a[N],M=1e9,s,c;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		M=min(M,abs(a[i])),s+=abs(a[i]);
		if(a[i]<0)
			c++;
	}
	if(c&1)
		cout<<s-2*M;
	else
		cout<<s;
	return 0;
}
