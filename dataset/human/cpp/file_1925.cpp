#include<iostream>
#include<ios>
using namespace std;
int n;
int f(char c)
{
	if(c<='9')return c-'0';
	else return c-'a'+10;
}
main()
{
	cin>>n;
	for(;n--;)
	{
		string s;cin>>s;
		bool hugou=0;
		int d;
		double a;
		hugou=f(s[0])/8;
		d=f(s[0])%8;
		for(int i=1;i<=5;i++)
		{
			d=d*16+f(s[i]);
		}
		d=d*2+f(s[6])/8;
		a=f(s[6])%8*16+f(s[7]);
		if(hugou)cout<<'-';
		if(a==0)cout<<d<<".0";
		else printf("%.15g",d+a/128);
		cout<<endl;
	}
}
