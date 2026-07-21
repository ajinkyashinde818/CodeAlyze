// see https://gist.github.com/LumaKernel/ff55d49ee1af69b7388f15b707e75c15
const bool DEBUG = 0;
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <complex>
#include <random>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll> P;
typedef tuple<ll, ll, ll> P3;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<P> VP;

#define omajinai ios::sync_with_stdio(false);cin.tie(0)

#define FOR(i,a,b) for(int i=(a);i<int(b);++i)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(b)-1;i>=int(a);--i)
#define RREP(i,n) RFOR(i,0,n)

#define LFOR(i,a,b) for(ll i=(a);i<(b);++i)
#define LREP(i,n) LFOR(i,0,n)
#define LRFOR(i,a,b) for(ll i=(b)-1;i>=(a);--i)
#define LRREP(i,b,a) LRFOR(i,0,n)

#define ALL(a) (a).begin(),(a).end()
#define UNIQUE(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
#define MP make_pair
#define PB push_back
#define EACH(i,c) REP(i,(int)(c).size())
#define REACH(i,c) RREP(i,(int)(c).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define BR cout << "\n"

#define dump(x) if(DEBUG)cerr<<"[" << __LINE__ << "] "<<#x<<"="<<(x)<<"\n"
#define dump2(x,y) if(DEBUG)cerr<<"["<<__LINE__<< "] "<<#x<<"="<<(x)\
  <<" , "<<#y<<"="<<(y)<<"\n"
#define dump3(x,y,z) if(DEBUG)cerr<<"["<<__LINE__<< "] "<<#x<<"="<<(x)\
  <<" , "<<#y<<"="<<(y)<<"\n"\
  <<" , "<<#z<<"="<<(z)<<"\n"

#define SAY(x) if(DEBUG) cerr << "[" << __LINE__ << "] " << (x) << "\n"

#define YES(x) cout<<((x)?"YES":"NO")<<"\n"
#define Yes(x) cout<<((x)?"Yes":"No")<<"\n"
#define yes(x) cout<<((x)?"yes":"no")<<"\n"

int int_in(){int n;cin>>n;return n;}
ll ll_in(){ll n;cin>>n;return n;}
string string_in(){string n;cin>>n;return n;}
#define ini int_in()
#define inl ll_in()
#define ins string_in()

#define inside(x,y) (0<=(x)&&(x)<w&&0<=(y)&&(y)<h)

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

ll ans;

struct trie{
	trie *zero = nullptr, *one = nullptr;
	trie* mkzero(){
		if(zero==nullptr){
			trie x;
			this->zero = new trie;
		}
		return this->zero;
	}
	trie* mkone(){
		if(one==nullptr){
			trie x;
			this->one = new trie;
		}
		return this->one;
	}
	ll solve(ll l,int c){
		ll ret=0;ll h=l-c;
		if(zero==nullptr) {ret^=h&(-h);}
		else {ret^=zero->solve(l, c+1);}
		if(one==nullptr) {ret^=h&(-h);}
		else {ret^=one->solve(l, c+1);}
		return ret;
	}
};

int main() {
	omajinai;
	//#####//
	int n=ini;ll l=inl;
	trie root;
	REP(i, n){
		string s=ins;
		trie* it = &root;
		REP(j,s.size()){
			if(s[j]=='0'){
				it=it->mkzero();
			}else{
				it=it->mkone();
			}
		}
	}
	cout<<(root.solve(l,0)?"Alice":"Bob");BR;
}
