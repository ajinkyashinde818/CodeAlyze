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
#include<unordered_set>

#define DBG cerr << '!' << endl;
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
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

struct node
{
	node():left(-1),right(-1),depth(1){}
	int left,right,depth;
};
node memo[100010];

unordered_set<ll> mp;

ll f(ll n)
{
	ll ret = 1;
	if(n == 0)return 0;
	while(n % (ret*2) == 0)
	{
		ret *= 2;
	}
	return ret;
}

int main()
{
	ll n,l;cin >> n >> l;l++;
	int po = 1;
	REP(i,n)
	{
		string tmp;cin >> tmp;
		ll str = 0;
		REP(i,tmp.size())
		{
			int tmtm = str;
			if(tmp[i] == '0')str = memo[str].left;
			else str = memo[str].right;
			if(str == -1)
			{
				if(tmp[i] == '0')memo[tmtm].left = po;
				else memo[tmtm].right = po;
				str = po;memo[str].depth = memo[tmtm].depth+1;
				po++;
			}
		}
	}
	
	
	ll ans = 0;
	REP(i,po)
	{
		ll cou = 0;
		if(memo[i].left == -1)cou++;
		if(memo[i].right == -1)cou++;
		
		if(cou == 1)
		{
			ll tmp = f(l - memo[i].depth);
			ans ^= tmp;
		}
	}
	
	
	if(ans == 0)
	{
		cout << "Bob" << endl;
	}
	else
	{
		cout << "Alice" << endl;
	}
	
	return 0;
}
