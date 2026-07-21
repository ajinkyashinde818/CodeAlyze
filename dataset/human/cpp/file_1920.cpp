#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <valarray>
#include <vector>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(__typeof((X).begin()) it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)x.size())

using namespace std;

struct timer{
	time_t start;
	timer(){start=clock();}
	~timer(){cerr<<1.*(clock()-start)/CLOCKS_PER_SEC<<" secs"<<endl;}
};

typedef istringstream iss;
typedef long long ll;
typedef pair<int,int> pi;
typedef stringstream sst;
typedef vector<int> vi;

int Q;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>Q;
	while(Q--){
		string s;
		cin>>s;
		int b[33];
		rep(i,sz(s)){
			int m=isdigit(s[i]) ? s[i]-'0' : s[i]-'a'+10;
			rep(j,4){
				b[4*i+j] = m>>(3-j)&1;
			}
		}
		int v=0;
		rep2(i,1,32)v|=b[i]<<(31-i);
		if(b[0]==1)cout<<"-";
		if((v&127)==0){
			cout<<v/128<<".0"<<endl;
		}
		else{
			cout<<setprecision(16)<<v/128.<<endl;
		}
	}
}
