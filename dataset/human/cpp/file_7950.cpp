#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long i=0,n,m,x=0,y=0,a[214514];
	for(cin>>n;i<n;cin>>a[i],x+=a[i++]);
	for(i=0;i<n-1;i++)
	{
		y+=a[i];
		x-=a[i];
		if(i==0)m=abs(x-y);
		else m=min(m,abs(x-y));
	}
	cout<<m<<endl;
	return 0;
}
