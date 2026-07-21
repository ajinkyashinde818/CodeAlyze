#include <iostream>
#include <fstream>
#include <cassert>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#include <random>
#include <complex>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<long double,long double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<61;
const double pi=acos(-1);
const double eps=1e-10;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

ll n,l;
vs a;

int f(string s,string t){
	int i=0;
	while(s[i]==t[i]) i++;
	return i;
}

ll g(ll x){
	if(!x) return 0;
	ll y=1,t=0;
	while(y<x){
		y*=2;
		t++;
	}
	if(y==x) return 1ll<<t;
	return g(x-y/2);
}

int main(){
	cin>>n>>l;
	a=vs(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	ll x=0;
	for(int i=0;i<n-1;i++){
		int t=f(a[i],a[i+1]);
		for(int j=t;j<=a[i].size()-1;j++) x^=g(l-j);
	}
	for(int i=0;i<a[n-1].size();i++) x^=g(l-i);
	if(x) cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
}
