#include<bits/stdc++.h>
using namespace std;
int arr[2*100000+5];
long long Abs(long long a,long long b)
{
	if(a>b)
		return a-b;
	else
		return b-a;
}
int main()
{
	int t;
	long long m,s=0,s1=0,s2=0,mins=2*1e15;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&arr[i]);
		s+=arr[i];
	}
	for(int i=0;i<t-1;i++)
	{
		s1+=arr[i];
		s2=s-s1;
		if(mins>Abs(s1,s2))
			mins=Abs(s1,s2);
		if(mins==0)
			break;
	}
	cout<<mins<<endl;
	return 0;
}
