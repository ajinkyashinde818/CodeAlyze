#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<complex>

using namespace std;


const long long int mod=1000000007;
int main(){
	cout << fixed << setprecision(18);
	string str[300];
	char ch;
	long long int n,c,x[200000],v[200000],left[200000]={},left2[200000]={},right[200000]={},right2[200000]={},res=0;
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>v[i];
	}
	long long int now=v[1]-x[1];
	right[1]=max(0LL,now);
	for(int i=2;i<=n;i++)
	{
		now+=v[i]-x[i]+x[i-1];
		right[i]=max(right[i-1],now);
	}
	
	now=v[1]-2*x[1];
	right2[1]=max(0LL,now);
	for(int i=2;i<=n;i++)
	{
		now+=v[i]-2*(x[i]-x[i-1]);
		right2[i]=max(right2[i-1],now);
	}
	
	
	now=v[n]+x[n]-c;
	left[n]=max(0LL,now);
	for(int i=n-1;i>=1;i--)
	{
		now+=v[i]-(x[i+1]-x[i]);
		left[i]=max(left[i+1],now);
	}
	
	now=v[n]+2*(x[n]-c);
	left2[n]=max(0LL,now);
	for(int i=n-1;i>=1;i--)
	{
		now+=v[i]-2*(x[i+1]-x[i]);
		left2[i]=max(left2[i+1],now);
	}
	
	
	for(int i=0;i<=n;i++)
	{
		res=max(res,right[i]+left2[i+1]);
		res=max(res,right2[i]+left[i+1]);
		
	}
	cout<<res<<endl;
}
