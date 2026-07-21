#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <time.h>

using namespace std;
typedef long long ll;
#define pl pair<ll,ll>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define dbg(x) cout << #x"="<< (x) << endl
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back(a) 
#define in(x) cin >> x;
#define all(x) (x).begin(), (x).end()
#define INF 2147483600
#define fi first
#define se second
ll n,m;
vector<string> a(n),b(m);
bool solve(int i, int j){
	bool flag=true;
	FOR(k,i,i+m){
		if(a[k].substr(j,m)!=b[k-i]){
			flag=false;
		}
	}
	return flag?true:false;
}
int main(){
	cin>>n>>m;
	string s;
	rep(i,n){
		cin>>s;
		a.pb(s);
	}
	rep(i,m){
		cin>>s;
		b.pb(s);
	}
	//始点を決める(i,j)
	rep(i,n-m+1){
		rep(j,n-m+1){
			if(solve(i,j)){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
    return 0;
}
