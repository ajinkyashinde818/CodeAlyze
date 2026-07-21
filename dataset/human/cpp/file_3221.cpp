#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long calmin=0;	
	long long n;
	cin>>n;
	vector<long long> a(n);
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0)
		{
			calmin++; 
			a[i]=a[i]*-1;
		} 
	}
	sort(a.begin(),a.end());
	long long sum=0;
	for(long long i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	if(calmin%2!=0)
	{
		cout<<sum-2*a[0];
		return 0;
	}
	else
	{
		cout<<sum;
		return 0;
	}
}
