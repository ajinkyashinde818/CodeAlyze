#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<bitset>
#include<stack>
#include<cassert>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mem(x,y) memset(x,y,sizeof x)
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
const int INF=2e9;
const db eps=1e-12;
template<typename T>
inline void read(T &x) {
  x=0; int f=1; char ch=getchar();
  while( (ch<'0' || ch>'9') && ch!='-') ch=getchar(); if(ch=='-') {f=-1; ch=getchar();}
  while(ch>='0' && ch <='9') x=x*10+ch-'0',ch=getchar();
  x*=f;
}
//==========================head template==========================
const int N=100010;
int a[N],b[N];
int tmp[2][N];
int n;
int fat[N];
int father(int x) {return fat[x]==x ? x : fat[x]=father(fat[x]);}
int ans=0;
bool vis[N];
map<int,int> key;
signed main() {
  read(n);
  for(int i=1;i<=n;i++) read(a[i]);
  for(int i=1;i<=n;i++) a[n+1]^=a[i];
  for(int i=1;i<=n;i++) read(b[i]);
  for(int i=1;i<=n;i++) b[n+1]^=b[i];
  memcpy(tmp[0],a,sizeof(a)); memcpy(tmp[1],b,sizeof(b));
  for(int i=0;i<2;i++) sort(tmp[i]+1,tmp[i]+n+2);
  ++n;
  for(int i=1;i<=n;i++) if(tmp[0][i]!=tmp[1][i]) {puts("-1"); return 0;}
  int tot=0;
  for(int i=1;i<=n;i++) if(!key.count(tmp[0][i])) key[tmp[0][i]]=++tot;
  //for(int i=1;i<=tot;i++) ++tmp[0][i];
  //for(int i=1;i<=n;i++) printf("%d ",tmp[0][i]); puts("");
  //tot=unique(tmp[0],tmp[0]+tot+1)-tmp[0]-1;
  //for(int i=1;i<=tot;i++) --tmp[0][i];
  for(int i=1;i<=n;i++) a[i]=key[a[i]];
  for(int i=1;i<=n;i++) b[i]=key[b[i]];
  for(int i=1;i<=tot;i++) fat[i]=i;
  for(int i=1;i<=n;i++) {
    //printf("%d %d\n",a[i],b[i]);
    if(a[i]!=b[i]) ans+=(i<n); else continue;
    int fx=father(a[i]),fy=father(b[i]);
    if(a[i]!=b[i]) {
      fat[fx]=fy;
      vis[fx]=vis[fy]=1;
    }
  }
  if(!ans) {puts("0"); return 0;}
  vis[a[n]]=vis[b[n]]=1;
  for(int i=1;i<=tot;i++)
    if(father(i)==i && vis[i]) ++ans;
  ans-=1;
  printf("%d\n",ans);
  return 0;
}
