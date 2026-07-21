#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	long long a[200000+5];
	long long n,min,x,sum;
	while (cin>>n)
	{
		sum=min=0;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			min=min+fabs(a[i]);
			sum=sum+a[i];
		}
		x=0;
		for (int i=n-1;i>0;i--)
		{
			x=x+a[i];
			if(fabs(2*x-sum)<min)
			min=fabs(2*x-sum);
		}
		cout<<min<<endl;
	}
}
