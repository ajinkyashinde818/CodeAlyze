#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
const long long mod=1000000000+7;
int n;
long long ans=1,cou=0;
bool a[maxn*2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		char ch;ch=getchar();
		while(ch!='B'&&ch!='W') ch=getchar();
		if(ch=='B') a[i]=1;
		else a[i]=0;
	}
	for(int i=1;i<=2*n;i++)
	{
		if(((i-1)&1)==a[i]) {ans=ans*cou%mod;--cou;}
		else ++cou;
		if(cou<0) {printf("0\n");return 0;}
	}
	if(cou>0) {printf("0\n");return 0;}
	for(long long i=1;i<=n;i++) ans=ans*i%mod;
	printf("%lld\n",ans);
	return 0;
}
