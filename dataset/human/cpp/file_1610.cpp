#include<cstring>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for (int i=(a);i<(b);i++)
#define per(i,a,b) for (int i=(b)-1;i>=a;i--)
#define sz(a) (int) a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
//-----
const double eps = 1e-8;
const int inf = 0x7f7f7f7f;
const int N=1e5+5;
const int mod=1e9+7;
vector<pii> p;
vector<int> e[N];
int main()
{
	
	ll n; cin>>n;
	ll m = 1;
	while(m * (m-1) / 2 < n) m++;
	if(m*(m-1)/2 != n) {
		cout<<"No"<<endl;
		return 0; 
	}
	//printf("Yes\n%d\n",m);
	cout<<"Yes"<<endl<<m<<endl;
	int d = 1;
	rep(i,1,m+1) {
		rep(j,i+1,m+1) {
			e[i].pb(d);
			e[j].pb(d);
			d++;
		}
	}
	rep(i,1,m+1) {
		cout<<m-1;
		rep(j,0,m-1) cout<<' '<<e[i][j];
		cout<<endl;
	}
	return 0;
}
