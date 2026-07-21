#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long sum;
int mn=1e9+7,c=0;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		if(a<0)c^=1,mn=min(mn,-a);
		else mn=min(mn,a);
		sum+=abs(a);
	}
	cout<<sum-2*(c?mn:0)<<"\n";
	return 0;
}
