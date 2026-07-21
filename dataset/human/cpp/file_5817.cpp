#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <string.h>
#include <sstream>
#include <ctime>

using namespace std;

#define eps 1e-12
#define pi 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define bgn begin
#define ll long long
#define ld long double
#define ull unsigned long long
#define ii pair<ll,ll>





const int N=1e5+10;
ll n,c,res,x[N],v[N],mx[N],s[4][N];



void f()
{
	s[1][0]=0;
	for(int i=1;i<=n;i++)
	{
		s[1][i]=s[1][i-1]+v[i];
	}
	s[2][n+1]=0;
	mx[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		s[2][i]=s[2][i+1]+v[i];
		mx[i]=max(s[2][i]-(c-x[i]),mx[i+1]);
	}
	for(int i=0;i<=n;i++)
	{
		res=max(res,s[1][i]-(2*x[i])+mx[i+1]);
	}
}




void solve()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>v[i];
	}
	res=0;
	f();
	for(int i=1;i<=n;i++)x[i]=c-x[i];
	reverse(x+1,x+n+1);
	reverse(v+1,v+n+1);
	f();
	cout<<res<<"\n";
}

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef localProject
	freopen("in.txt","r",stdin);
#endif
	solve();
	return 0;
}
