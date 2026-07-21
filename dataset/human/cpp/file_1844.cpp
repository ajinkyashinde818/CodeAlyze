#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<functional>
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
#define SHOW1d(v,n) {for(int i = 0;i < (n);i++)cerr << v[i] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

bool memo[200010];

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> v;
	
	REP(i,m)
	{
		int a;cin >> a;
		v.PB(a);
	}
	
	for(int i = v.size()-1;i >= 0;i--)
	{
		if(!memo[v[i]])
		{
			cout << v[i] << endl;
			memo[v[i]] = true;
		}
	}
	
	for(int i = 1;i <= n;i++)
	{
		if(!memo[i])
		{
			cout << i << endl;
		}
	}
	
	return 0;
}
