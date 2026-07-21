#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

int getint()
{
    char ch=getchar();
    int f=1,x=0;
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
    return f*x;
}

const int N=100100;

int n;
int a[N],a2[N];
int b[N],b2[N];
int fa[N];
bool vis[N];
vector<int> g[N];
int idx[N];
pair<int,int> c[N];
int sm,lpcnt;

int getfa(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}

void merge(int x,int y)
{
    x=getfa(x);
    y=getfa(y);
    if(x==y) return;
    fa[x]=y;
}

void dscrt(int a[])
{
    for(int i=0; i<=n; i++){
        c[i].first=a[i];
        c[i].second=i;
    }
    sort(c,c+1+n);
    int tmp=0;
    a[c[0].second]=++tmp;
    for(int i=1; i<=n; i++){
        tmp+=c[i].first!=c[i-1].first;
        a[c[i].second]=tmp;
    }
}

void init()
{
    n=getint();
    for(int i=1; i<=n; i++){
        a[i]=a2[i]=getint();
        a[0]^=a[i];
        a2[0]^=a[i];
    }
    for(int i=1; i<=n; i++){
        b[i]=b2[i]=getint();
        b[0]^=b[i];
        b2[0]^=b[i];
    }
    sort(a2,a2+1+n);
    sort(b2,b2+1+n);
    for(int i=0; i<=n; i++) fa[i]=i;
    dscrt(a);
    dscrt(b);
    /*
    for(int i=0; i<=n; i++){
        printf("%d ",a[i]);
    }
    puts("");
    for(int i=0; i<=n; i++){
        printf("%d ",b[i]);
    }
    puts("");
    */
}

int main()
{
    init();
    bool flag=false;
    for(int i=0; i<=n; i++){
        if(a2[i]!=b2[i]){
            flag=true;
            break;
        }
    }
    if(flag){
        puts("-1");
        return 0;
    }
    for(int i=1; i<=n; i++){
        sm+=a[i]==b[i];
    }
    for(int i=0; i<=n; i++){
        g[a[i]].push_back(i);
    }
    for(int i=0; i<=n; i++){
        merge(i,g[b[i]][idx[b[i]]++]);
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j+1<(int)g[i].size(); j++){
            merge(g[i][j],g[i][j+1]);
        }
    }
    for(int i=0; i<=n; i++){
        if(i!=0 && a[i]==b[i]) continue;
        int tmp=getfa(i);
        if(!vis[tmp]){
            vis[tmp]=true;
            lpcnt++;
        }
    }
    //printf("%d\n",lpcnt);
    printf("%d\n",max(0,n+lpcnt-1-sm));
    return 0;
}
