#include<bits/stdc++.h>
using namespace std;
int n,s[1000010],t[1000010],sx[1000010],tx[1000010],x=0,y=0,ans=0,m=0,fa[1000010];
map <int,int> pos;
void judge()
{
    bool flag=false;
    for (int i=1;i<=n;++i)
        if (sx[i]!=tx[i])
        {
            flag=true;
            break;
        }
    if (!flag)
    {
        cout<<"0"<<endl;
        exit(0);
    }
    sort(sx+1,sx+n+2),sort(tx+1,tx+n+2);
    for (int i=1;i<=n+1;++i)
        if (sx[i]!=tx[i])
        {
            cout<<"-1"<<endl;
            exit(0);
        }
}
int find(int x)
{
    if (fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
int main()
{
    pos.clear();
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&s[i]);
        x^=s[i],sx[i]=s[i];
    }
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&t[i]);
        y^=t[i],tx[i]=t[i];
    }
    sx[n+1]=s[n+1]=x;
    tx[n+1]=t[n+1]=y;
    judge();
    for (int i=1;i<=n;++i)
        if (s[i]!=t[i])
        {
            ++ans;
            if (pos[s[i]]==0) pos[s[i]]=++m;
            if (pos[t[i]]==0) pos[t[i]]=++m;
        }
    if (pos[s[n+1]]==0) pos[s[n+1]]=++m;
    if (pos[t[n+1]]==0) pos[t[n+1]]=++m;
    for (int i=1;i<=m;++i) fa[i]=i;
    for (int i=1;i<=n;++i) if (s[i]!=t[i]) fa[find(pos[s[i]])]=find(pos[t[i]]);
    for (int i=1;i<=m;++i) if (fa[i]==i) ++ans;
    printf("%d\n",ans-1);
}
