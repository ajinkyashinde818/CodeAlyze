#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <cassert>
using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define F first
#define S second
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

int wx[100],wy[100],r[100];

main(){
  int n;
  while(cin>>n,n){
    rep(i,n)cin>>wx[i]>>wy[i]>>r[i];

    int m;
    cin>>m;
    while(m--){
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      bool safe=false;
      rep(i,n){
	if(a==c && b==d)break;
	int e=wx[i],f=wy[i],g=r[i];
	bool myin=(e-a)*(e-a)+(b-f)*(b-f)<g*g;
	bool enin=(e-c)*(e-c)+(f-d)*(f-d)<g*g;
	if(myin!=enin){
	  safe=true;
	  break;
	}
	if(myin && enin)continue;

	int varxy=(a*a-2*a*c+b*b-2*b*d+c*c+d*d);
	double xx=(a*a*e-a*b*d+a*b*f-2*a*c*e+a*d*d-a*d*f+b*b*c-b*c*d-b*c*f+c*c*e+c*d*f);
	xx=xx/varxy;
	double yy=(a*a*d-a*b*c+a*b*e-a*c*d-a*d*e+b*b*f+b*c*c-b*c*e-2*b*d*f+c*d*e+d*d*f);
	yy=yy/varxy;
	if((e-xx)*(e-xx)+(f-yy)*(f-yy)>g*g)continue;

	if((a<=xx && xx<=c) || (c<=xx && xx<=a)){
	  safe=true;
	  break;
	}
      }
      if(safe)cout<<"Safe"<<endl;
      else cout<<"Danger"<<endl;
    }
  }
}
