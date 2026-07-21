#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],b[N],n,val,cnt;
vector<int> p,q;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
		a[i]=read();
	for(register int i=1;i<=n;i++)
		b[i]=read();
	reverse(b+1,b+1+n);
	for(register int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
			continue;
		cnt++;
		p.push_back(i);
		val=b[i];
	}
	for(register int i=1;i<=n;i++)
	{
		if(!cnt)
			break;
		if(a[i]==b[i])
			continue;
		if(a[i]!=val&&b[i]!=val)
		{
			cnt--;
			q.push_back(i);
		}
	}
	if(cnt)
	{
		puts("No");
		return 0;
	}
	for(register int i=0;i<q.size();i++)
		swap(b[p[i]],b[q[i]]);
	puts("Yes");
	for(register int i=1;i<=n;i++)
		printf("%d ",b[i]);
	puts("");
	return 0;
}
