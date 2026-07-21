#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e8;
int main(){
	int n,a;
	cin>>n>>a;
	vi out;
	if(n%2){
		rep(i,n/2+1)out.pb(0);
		rep(i,n/2)out.pb(a);
	}else{
		rep(i,n/2-1)out.pb(0);
		rep(i,n/2+1)out.pb(a);
	}
	rep(i,out.size()-1)cout<<out[i]<<" ";
	cout<<out[n-1]<<endl;
}
