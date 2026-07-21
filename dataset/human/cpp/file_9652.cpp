#include<ctime>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath> 
#include<cstring>
#include<cassert>
#include<string>
#include<sstream>
#include<fstream>
#include<deque>
#include<queue>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<set>
#include<bitset>
#include<iomanip>
#include<utility>
#include<functional>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cwchar>
#include<cwctype>
#include<exception>
#include<locale>
#include<numeric>
#include<new>
#include<stdexcept>
#include<limits>
using namespace std;

#define ll long long
#define INF 1e9
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
#define pii pair<int,int> 
#define N (1<<7)

int n,m;
char a[55][55],b[55][55];

bool _check(int x,int y)
{
	if(x+m>n||y+m>n)return false;
	for(int i=x;i<x+m;i++)for(int j=y;j<y+m;j++)
	{
		if(a[i][j]!=b[i-x][j-y])return false;
	}
	return true;
}

int main()
{
	cin>>n>>m;
	rep(i,n)cin>>a[i];
	rep(i,m)cin>>b[i];
	rep(i,n)rep(j,n)
	if(_check(i,j)==true)
	{
		cout<<"Yes";
		return 0;
	}
	cout<<"No";
}
