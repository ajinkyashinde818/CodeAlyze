#include<map>
#include<stack>
#include<queue>
#include<string>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e6+5;
int n,ans,res,sit,a[maxn],b[maxn];
int main()
{
	//ios::sync_with_stdio(false);
    //cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    for(int i=n;i>=1;i--)
		cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i])
		{
			bool flag=0;
			for(int j=1;j<=n;j++)
			{
				if(a[i]!=b[j]&&a[j]!=b[i])
				{
					swap(b[i],b[j]);
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
	cout<<endl;
    return 0;
}
