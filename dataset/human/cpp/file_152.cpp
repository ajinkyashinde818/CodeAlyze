#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r,g,b,n,an=0;
	cin>>r>>g>>b>>n;
	int a,c,p,q;
	a=n/r;
	for(int i=0;i<=(n/r);i++)
	{
		c=(n-i*r)/g;
		for(int j=0;j<=c;j++)
		{
			p=n-i*r-j*g;
			if(p%b==0)
			an++;
		}
		
	}
	
	cout<<an;
	return 0;
}
