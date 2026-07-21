#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;


typedef pair<ll,ll> P;
long long int INF = 1e18;
double Pi = 3.141592653589;
const int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする

vector<int> G[100005];
std::vector<P> tree[100010];

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define re(i,a,b) for(i=a;i<=b;i++)

ll i,j,ii,jj;
ll n,m;
ll now=0,tyakuti=0,memo=0;
ll kaisi,k,hazime,owari;
ll a[100005];
long double x[100005],y[100005],r[100005];
long double d[1005][1005];//d[i][j]:i~j
long double cost[1005];
bool kakutei[1005];


int main(){
    cin>>x[0]>>y[0]>>x[1]>>y[1];
    r[0]=r[1]=0;
    /*x[0]/=100.0000;
    x[1]/=100.0000;
    y[0]/=100.0000;
    y[1]/=100.0000;*/
    cin>>n;
    for(i=2;i<n+2;i++){
        cin>>x[i]>>y[i]>>r[i];
        /*x[i]/=100.0000;
        r[i]/=100.0000;
        y[i]/=100.0000;*/
    }
    for(i=0;i<n+2;i++){
        cost[i]=INF;
    }
    for(i=0;i<n+2;i++){
        for(j=0;j<n+2;j++){
            long double ddx=x[i]-x[j],ddy=y[i]-y[j];
            d[i][j]=sqrt(ddx*ddx+ddy*ddy)-r[i]-r[j];
            if(d[i][j]<0)d[i][j]=0;
        }
    }
    cost[0]=0;
    while(true){
        ll v=-1;
        for(i=0;i<n+2;i++){
            if(!kakutei[i] && (v==-1 || cost[i]<cost[v])){
                v=i;
            }
        }
        
        if(v==-1)break;
        kakutei[v]=true;
        bool flag=false;
        for(i=0;i<n+2;i++){
            if(!kakutei[i]){
                cost[i] = min(cost[i],cost[v] + d[i][v]);
                flag = true;
            }
        }
        if(!flag)break;
    }
    cout<< fixed << setprecision(20) <<(double)cost[1]*1.0000000000000<<endl;
    
    
    
    
    return 0;
}
