#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<functional>
#include<stack>
#include<queue>
#include <iomanip>
#include<map>
#include<limits>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<utility>
#include<complex>
#include<cstdlib>
#include<set>
#include<cctype>

#define DBG cerr << '!' << endl;
#define REP(i,n) for(int (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(int (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(int (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(10)

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

char a[100][100];
char b[100][100];
int n,m;

bool f(int h,int w)
{
	REP(i,m)
	{
		REP(j,m)
		{
			if(b[i][j] != a[i+h][j+w])return false;
		}
	}
	return true;
}

int main()
{
	cin >> n >> m;
	REP(i,n)
	{
		cin >> a[i];
	}
	REP(i,m)
	{
		cin >> b[i];
	}
	
	REP(i,n)
	{
		REP(j,n)
		{
			if(f(i,j))
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	
	cout << "No" << endl;
	
	
	return 0;
}
