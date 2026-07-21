#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
typedef long long ll;
typedef pair<int64_t,int64_t> pll;
int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,1,-1,-1,1};
#define INF (2147483647)
#define mod (1000000007)
#define limit (7368791)
#define rep(i,a,b) for (int64_t i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define ALL(a) begin(a),end(a)
#define sz(s) (s).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second


void solve()
{
    int n,m;cin>>n>>m;
    string a[n],b[m];
    REP(i,n)cin>>a[i];
    REP(i,m)cin>>b[i];
    int as=a[0].size(),bs=b[0].size();
    bool flag=0;
    REP(i,n-m+1){
        REP(j,as-bs+1){
            flag=0;
            REP(k,m){
                REP(l,bs){
                    if(b[k][l]!=a[k+i][l+j])flag=1;
                    if(flag)break;
                }
                if(flag)break;
            }
            if(!flag){cout<<"Yes"<<endl;return;}
        }
    }
    cout<<"No"<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}
