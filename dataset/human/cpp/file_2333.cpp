#include<iostream>
using namespace std;

int main()
{
	long long a,neg=0,sum=0,min=0;
	cin >> a;
	long long arr[a+10];
	for(long long i=1;i<=a;i++)
	{
		cin >> arr[i];
		if(arr[i]<0)
		{
			neg++;
		}
	}
	if(neg%2==0)
	{
		for(long long i=1;i<=a;i++)
		{
			if(arr[i]<0)
			{
				arr[i]=arr[i]*-1;
			}
		}
		for(long long i=1;i<=a;i++)
		{
			sum+=arr[i];
		}
	}
	else if(neg%2==1)
	{
		min = 9999999999;
		for(long long i=1;i<=a;i++)
		{
			if(arr[i]<0)
			{
				arr[i]=arr[i]*-1;
			}
		}
		
		for(long long i=1;i<=a;i++)
		{
			if(arr[i]<=min)
			{
				min=arr[i];
			}
		}
		
		for(long long i=1;i<=a;i++)
		{
			sum+=arr[i];
		}
		sum=sum-2*min;
	}
	cout << sum << endl;
}
