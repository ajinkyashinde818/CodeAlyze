#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;

int Next[maxn][2],cnt;
char shit[maxn];
void add()
{
    int root=0;
    int l=strlen(shit);
    for(int i=0;i<l;i++)
    {
        int t=shit[i]-'0';
        if(Next[root][t]==-1){
            Next[root][t]=cnt++;
        }
        root=Next[root][t];
    }
}
long long dfs(int u,int dep,long long l)
{
    if(Next[u][0]==-1&&Next[u][1]==-1)
         return 0;
    long long sg=0;
    if(Next[u][0]==-1||Next[u][1]==-1)
    {
        long long tmp=l-dep;
        sg=sg^(tmp&(-tmp));
    }
    if(Next[u][0]!=-1)
        sg^=dfs(Next[u][0],dep+1,l);
    if(Next[u][1]!=-1)
        sg^=dfs(Next[u][1],dep+1,l);
    return sg;
}
int main()
{
    memset(Next,-1,sizeof(Next));
    cnt=1;
    int n;
    long long l;
    scanf("%d%lld",&n,&l);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",shit);
        add();
    }
    long long sg=dfs(0,0,l);
    if(sg) puts("Alice");
    else puts("Bob");
    return 0;
}
