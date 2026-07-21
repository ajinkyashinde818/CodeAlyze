#include <bits/stdc++.h>
using namespace std;
int a[30];
int main()
{
	char c;
	int n,i;
	long long ans=1;
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++)
	{
		scanf("%c",&c);
		a[c-'a']++;
	}
	for(i=0;i<26;i++)
		ans=ans*(a[i]+1)%1000000007;
	printf("%lld",(ans+1000000006)%1000000007);
    return 0;
}
