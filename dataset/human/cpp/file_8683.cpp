#include<iostream>
using namespace std;
int n,m;
string s[50],t[50];
bool check1(int a,int b,int x,int y)
{
	return s[a][b]==t[x][y];
}
int check(int a,int b)
{
	bool f=true;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			f&=check1(a+i,b+j,i,j);
		}
	}
	return f;
}
main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<m;i++)cin>>t[i];
	int cnt=0;
	for(int i=0;i<=n-m;i++)
	{
		for(int j=0;j<=n-m;j++)
		{
			cnt+=check(i,j);
		}
	}
	cout<<(cnt?"Yes":"No")<<endl;
}
