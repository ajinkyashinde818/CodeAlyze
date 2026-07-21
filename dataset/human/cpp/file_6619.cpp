#include<iostream>
using namespace std;
long long fact(int x)
{
	long long g=1;
	for(int i=2;i<=x;i++)
	{
		g*=i;
		g%=1000000007;
	}
	return g; 
}
int main()
{
	string s;
	long long k,n,l=0,ans=1;
	cin>>n;
	cin>>s;
	n*=2;
	for(int i=0;i<n;i++)
	{
		k=l%2;
		/*if(i>0 &&i<=n/2)
		{
			ans*=i;
			ans%=1000000007;
		}*/
		if((s[i]=='B' && k==1) || (s[i]=='W' && k==0))
		{
			ans*=l;
			ans%=1000000007;
			l--;
		}
		else
			l++;
		if(l<0 || l>n/2)
			break;	
	}
	if(l!=0)
		cout<<0<<endl;	
	else	
		cout<<(ans*fact(n/2))%1000000007<<endl;
}
