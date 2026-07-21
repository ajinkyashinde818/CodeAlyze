#include<bits/stdc++.h>
using namespace std;
namespace FAST_IO
{
	template<typename T> void read(T &a)
	{
		a=0;
		int f=1;
		char c=getchar();
		while(!isdigit(c))
		{
			if(c=='-')
			{
				f=-1;
			}
			c=getchar();
		}
		while(isdigit(c))
		{
			a=a*10+c-'0';
			c=getchar();
		}
		a=a*f;
	}
	template <typename T> void write(T a)
	{
		if(a<0)
		{
			a=-a;
			putchar('-');
		}
		if(a>9)
		{
			write(a/10);
		}
		putchar(a%10+'0');
	}
	template <typename T> void writeln(T a)
	{
		write(a);
		puts("");
	}
}
long long r,g,b,n,ans;
int main()
{
	cin>>r>>g>>b>>n;
	for(long long i=0;i<=n;i++)
	{
		for(long long j=0;j<=n;j++)
		{
			long long tmp=n-(i*r)-(j*g);
			if(tmp%b==0&&tmp>=0)
			{
				ans++; 
			}
		}
	}
	cout<<ans;
}
