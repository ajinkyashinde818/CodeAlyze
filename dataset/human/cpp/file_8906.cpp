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
#include<stack>
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
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-9;
const int inf=1e8;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	int n,m;
	cin>>n>>m;
	vs a(n),b(m);
	rep(i,n)cin>>a[i];
	rep(i,m)cin>>b[i];
	rep(i,n-m+1)rep(j,n-m+1){
		bool h=true;
		rep(x,m)rep(y,m)if(a[i+x][j+y]!=b[x][y])h=false;
		if(h){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}
