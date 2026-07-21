#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define rep(i,a,n) for(ll i =(a);i<(n);++i)
#define urep(i,a,n) for(ll i = (a);i>=(n);--i)
#define all(x) (x).begin(),(x).end()
#define INF 1e18
const int mod = 1e9 + 7;
typedef long long ll;
using namespace std;
ll dx[4] = { 1,-1,0,0 };
ll dy[4] = { 0,0,1,-1 };
ll N,M,X,Y,A,B,C,Q,K;
string S,T;
ll ans;
ll x[1000000];
ll y[1000000];
ll a[1000000];
ll b[1000000];
ll c[1000000];
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	else return gcd(b, a%b);
}
struct Edge{
	ll to,cost;
	 Edge(int to, int cost) : to(to), cost(cost) {}
};
typedef vector<vector<Edge> > AdjList;
AdjList graph;
vector<ll> dist;
ll possible[10000000];
int main() {
	cin>>N;
	if(N==1){
		cout<<"Yes"<<endl;
		cout<<2<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	rep(i,1,N){
		if(i*(i+1)>=10000000)break;
		possible[i*(i+1)]=i+1;
	}
	if(possible[N*2]==0){
		cout<<"No"<<endl;
	}else{
		ll num=possible[N*2];
		cout<<"Yes"<<endl;
		cout<<num<<endl;
		ll anstable[1000][1000];
		ll lastnum=0;
		for(int i=1;i<=num;++i){
			cout<<num-1;
			ll count=0;
			for(int j=1;j<i;++j){
				cout<<" "<<anstable[j][i-1];
				//anstable[i][j]=anstable[j][i-1];
				count++;
			}
			while(count<num-1){
				lastnum++;
				cout<<" "<<lastnum;
				count++;
				anstable[i][count]=lastnum;
			}
			cout<<endl;
		}
	}
	return 0;
}
