#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

const int MAXN=1e5+5;

int n,ncnt,tot,ans;
int a[MAXN],b[MAXN];
int in[MAXN],out[MAXN];
bool tag[MAXN];
map<int,int> vis;
vector<int> E[MAXN];

void dfs(int u){
    tag[u]=1;
    for(int i=0;i<(int)E[u].size();i++){
        int v=E[u][i];
        if(tag[v]) continue;
        dfs(v);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        tot^=a[i];
        if(vis.find(a[i])==vis.end()) vis[a[i]]=++ncnt;
        a[i]=vis[a[i]];
    }
    if(vis.find(tot)==vis.end()) vis[tot]=++ncnt;
    tot=vis[tot];
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        if(vis.find(b[i])==vis.end()) vis[b[i]]=++ncnt;
        b[i]=vis[b[i]];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==b[i]) continue;
        ans++;
        E[b[i]].push_back(a[i]);
        in[a[i]]++,out[b[i]]++;
    }
    bool flag=0;
    for(int i=1;i<=ncnt;i++){
        if(in[i]==out[i]) continue;
        if(in[i]<out[i]){
            if(in[i]!=out[i]-1||i!=tot)
                return puts("-1"),0;
        }
        else{
            if(in[i]!=out[i]+1||flag) return puts("-1"),0;
            flag=1;
        }
    }
    dfs(tot);
    for(int i=1;i<=ncnt;i++){
        if(tag[i]||!out[i]) continue;
        ans++;
        dfs(i);
    }
    printf("%d\n",ans);
}
