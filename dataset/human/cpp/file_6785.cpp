#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
inline int qr()
{
	int x=0,f=0;
	char ch=0;
	while(!isdigit(ch))
	{
		f=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
int n;
int a[maxn],b[maxn];
int p[maxn];
int cnt;
int val;
int main()
{
	n=qr();
	for(int i=1;i<=n;i++)
	{
		a[i]=qr();
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=qr();
	}
	reverse(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=a[i])continue;
		cnt++;
		p[cnt]=i;//相等的位置;
		val=b[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		if(!cnt) break;
		if(a[i]!=val&&b[i]!=val)//可以交换 
		swap(b[p[cnt--]],b[i]);
	}
	if(cnt) //位置不够 
	{
	printf("No");return 0;	
	}
	else {
		printf("Yes\n");
		for(int i=1;i<=n;i++)
		{
			printf("%d ",b[i]);
		}
	}
	return 0;
}
