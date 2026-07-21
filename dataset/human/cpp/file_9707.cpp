#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char a[100101];
int sum[1010];
int main()
{
	int n,i,ans=1;
	scanf("%d",&n);
	scanf("%s",a+1);
	for(i=1;i<=n;i++)
		sum[a[i]-'a']++;
	for(i=0;i<26;i++)
		ans=(long long)ans*(sum[i]+1)%1000000007;
	printf("%d\n",ans-1);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	return 0;
}
