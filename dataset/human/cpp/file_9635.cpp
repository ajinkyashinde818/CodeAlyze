#include <iostream>
#include <cstring>
#include<cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <ctime>
#include <cstring>
#include <cmath>
#include <stack>
#include <set>
#include <unordered_map>
#define INF 0x3f3f3f3f
#define ll long long
#define rep(i, n) for(ll i=0;i<n;i++)
#define per(i, n) for(int i=n;i>=0;i--)
#define rep2(i, n) for(ll i=1;i<=n;i++)
#define pb(x) push_back(x)
#define clint(x, n) memset(x,n,sizeof(x))
#define mp make_pair
#define fi first
#define se second
#define IO std::ios::sync_with_stdio(false)
#define ull unsigned long long
#define ud long double
#define pii pair<int,int>
using namespace std;
const int maxn = 1e6+5;
const ll inf = 100000000000;
const int mod =998244353;
const int MAX = 123123;
const int N =1005;
char a[55][55],b[55][55];
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    return s*w;
}
ll max(ll a,ll b){
    if(a>b) return a;
    return b;
}
ll min(ll a,ll b){
    if(a<b) return a;
    return b;
}
int main() {
    int m,n;
    cin>>n>>m;
    int flag=0,f=0;
    rep(i,n) rep(j,n) cin>>a[i][j];
    rep(i,m) rep(j,m) cin>>b[i][j];
    if(m>n) cout<<"No"<<endl;
    else{
        rep(i,n-m+1) {
            rep(j, n - m+1) {
                if (b[0][0] == a[i][j]) {
                    flag = 1;
                    for (ll x = 0; x < m; x++) {
                        for (ll y = 0; y < m; y++) {
                            if (b[x][y] != a[i + x][j + y]) {
                                flag = 0;
                            }
                        }
                    }
                    //cout<<i<<' '<<j<<' '<<f<<endl;
                    if (flag == 1) {
                        f = 1;
                        break;
                    }
                }
            }
            if(f) break;
        }
        if(f) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
