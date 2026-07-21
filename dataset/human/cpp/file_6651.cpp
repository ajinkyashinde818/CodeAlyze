#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1000000007;
int n,k,top,i;
ll ans=1;
char c[200005];
int main()
{
	scanf("%d",&n);
	scanf("%s",c+1);
	for(i=1;i<=n;i++)
		ans=ans*i%M;
	for(i=1;i<=n*2;i++)
	{
		if(c[i]=='B'&&top%2==0)
			top++;
		else
		if(c[i]=='B'&&top%2==1)
		{
			ans=ans*top%M;
			top--;
		}
		else
		if(c[i]=='W'&&top%2==0)
		{
			ans=ans*top%M;
			top--;
		}
		else
		if(c[i]=='W'&&top%2==1)
			top++;
		if(top<0)
		{
			printf("0");
			return 0;
		}
	}
	if(top!=0)
		printf("0");
	else
		cout<<ans;
}
