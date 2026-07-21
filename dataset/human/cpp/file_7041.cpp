#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],b[N];
int n;
int t[N],t1[N];
inline int read()
{
	int Num=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {Num=(Num<<1)+(Num<<3)+ch-'0'; ch=getchar();}
	return Num*f;
}
int tot=200,flag=0;
int main()
{
	n=read();int Bit=1,_bit=n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[n-i+1]=read();
	for(int i=1;i<=n;i++) 
	if(a[i]==b[i])  
	{
		if(b[Bit]!=a[i]&&b[i]!=a[Bit]) 
			swap(b[Bit++],b[i]);
		else if(b[_bit]!=a[i]&&a[_bit]!=b[i])
			swap(b[_bit--],b[i]);
		else 
		{
			puts("No");
			return 0;
		}
	}
		puts("Yes");
		for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
		return 0;
	return 0;
}
