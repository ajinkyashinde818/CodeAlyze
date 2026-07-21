#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a;
vector<int> G[100001];
int d[100001];
int p[100001][30];

int lca(int a,int b){
  if(d[a]<d[b])swap(a,b);
  for(int i=29;i>=0;i--)
    if((d[a]-d[b])>>i&1)
      a=p[a][i];
  if(a==b)return a;
  for(int i=29;i>=0;i--){
    if(p[a][i]!=p[b][i]){
      a=p[a][i];
      b=p[b][i];
    }
  }
  return p[a][0];
}

int main(){
  scanf("%d",&n);
  for(int i=2;i<=n;i++){
    scanf("%d",&a);
    G[a].push_back(i);
    p[i][0]=a;
  }
  p[1][0]=1;
  for(int k=1;k<30;k++){
    for(int i=1;i<=n;i++){
      p[i][k]=p[p[i][k-1]][k-1];
    }
  }
  for(int i=1;i<=n;i++){
    sort(G[i].begin(),G[i].end());
  }
  queue<int> Q;
  Q.push(1);
  int prev=1;
  ll ans=0;
  while(!Q.empty()){
    int pos=Q.front();Q.pop();
    ans+=(d[prev]+d[pos]-d[lca(prev,pos)]*2);
    for(int to:G[pos]){
      d[to]=d[pos]+1;
      Q.push(to);
    }
    prev=pos;
  }
  cout<<ans<<endl;
  return 0;
}
