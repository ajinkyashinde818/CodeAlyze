#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
char s[1000001];
signed main()
{
	int t;
	scanf("%d%d",&n,&t);
	if(n>=10)
		printf("%d",t);
	else
		printf("%d",t+100*(10-n));
	return 0;
}
