#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long s=0;
	long long t=0;
	long long f=9999999999;
	int a;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a<0)
		{
			t+=1;
			s+=a*-1;
			if(a*-1<f)
			f=a*-1;
		}
		else
		{
			s+=a;
			if(a<f)
			f=a;
		}
	}
	if(t%2==0)
	cout<<s;
	else
	cout<<s-f-f;
	return 0;
}
