#include<bits/stdc++.h>
using namespace std;
int n,a[202020],b[202020];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	reverse(b,b+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			continue;
		}
		bool ok=false;
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				continue;
			}
			if(a[i]!=b[j] && a[j]!=b[i])
			{
				swap(b[i],b[j]);
				ok=true;
				break;
			}
		}
		if(!ok)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	for(int i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}
	cout<<endl;
	return 0;
}
