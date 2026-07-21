#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	long long c;
	cin>>n>>c;
	long long x[n],v[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>x[i]>>v[i];
	}
	long long l[n],lb[n];
	l[0]=v[0]-x[0];
	lb[0]=max(0LL,l[0]);
	for (int i = 1; i < n; ++i)
	{
		l[i]=l[i-1]+v[i]-abs(x[i]-x[i-1]);
		lb[i]=max(lb[i-1],l[i]);
	}
	long long r[n],rb[n];
	r[n-1]=v[n-1]-abs(c-x[n-1]);
	rb[n-1]=max(0LL,r[n-1]);
	for (int i = n-2; i >= 0; --i)
	{
		r[i]=r[i+1]+v[i]-abs(x[i]-x[i+1]);
		rb[i]=max(rb[i+1],r[i]);
	}
	long long ans=0LL;
	for (int i = 0; i < n-1; ++i)
	{
		long long nans=l[i]+max(0LL,rb[i+1]-x[i]);
		ans=max(ans,nans);
	}
	ans=max(ans,l[n-1]);
	for (int i = 1; i < n; ++i)
	{
		long long nans=r[i]+max(0LL,lb[i-1]-abs(c-x[i]));
		ans=max(ans,nans);
	}
	ans=max(ans,r[0]);
	cout<<ans<<endl;
	return 0;
}
