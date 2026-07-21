#include <bits/stdc++.h>
using namespace std;
const int Q=(1<<19)+1,MOD=1e9+7;
inline int mul(int a,int b)
{return 1LL*a*b%MOD;}
char s[Q];
int main()
{
	int als=1;
	int n;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)als=mul(als,i);
	n<<=1;
	if(s[1]=='W'||s[n]=='W')return 0&puts("0");
	int ct=0;
	for(int i=1,now,lst;i<=n;i++){
		if(i==1)now=0;
		else if(i==n)now=1;
		else now=(s[i]==s[i-1])^lst;
		if(!now)++ct,lst=0;
		else{
			lst=1;
			if(!ct)return puts("0")&0;
			als=mul(als,ct),--ct;
		}
	}
	if(ct)return puts("0")&0;
	printf("%d\n",als);
	return 0;
}
