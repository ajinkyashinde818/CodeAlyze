#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
long long a[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n,i,br=0,l=0,s=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0)br++;
		if(abs(a[i])<abs(a[l]))l=i;
		s+=abs(a[i]);
	}
	cout<<s-(br&1)*abs(a[l])*2<<'\n';
}
