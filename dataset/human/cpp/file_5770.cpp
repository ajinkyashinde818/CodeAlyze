#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
typedef long long ll;
int n,rt=1,tot=1,ch[N][2];
bool lev[N];
ll l,sg;
char s[N];
void Insert()
{
    int now=rt;
    for(int i=1;s[i];i++)
    {
        int p=s[i]-'0';
        if(!ch[now][p]) ch[now][p]=++tot;
        now=ch[now][p];
    }
    lev[now]=true;
}
ll getsg(ll x)
{
    if(x==0) return 0;
    ll ans=1;
    while(x%4==0)
    {
        x/=4;ans*=4;
    }
    if(x%4==1||x%4==3) return ans;
    return ans*2;
}
void dfs(int u,int dep)
{
    if(lev[u]) return;
    if(!ch[u][0]||!ch[u][1])
    {
        sg^=getsg(l-dep);
    }
    if(ch[u][0]) dfs(ch[u][0],dep+1);
    if(ch[u][1]) dfs(ch[u][1],dep+1);
}
int main()
{
    scanf("%d%lld",&n,&l);
    while(n--)
    {
        scanf("%s",s+1);
        Insert();
    }
    dfs(rt,0);
    if(sg) printf("Alice\n");
    else printf("Bob\n");
}
