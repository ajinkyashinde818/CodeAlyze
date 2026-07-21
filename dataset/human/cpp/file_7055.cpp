#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[200010],b[200010],d[200010],nxt[200010],ans[200010],pre[200010];
struct dian
{
    int x,y;
}c[200010];
int n;
bool cmp(const dian &x,const dian &y)
{
     return x.y>y.y;
}
int main()
{
    int i,t,now,u;
    srand((unsigned)time(NULL));
    cin>>n;
    for(i=1;i<=200000;i++) c[i].x=i;
    for(i=1;i<=n;i++) 
    {
        cin>>a[i];
        c[a[i]].y++;
    }
    for(i=1;i<=n;i++)
    {
        cin>>b[i];
        d[b[i]]++;
        c[b[i]].y++;
    }
    for(i=1;i<=200000;i++)
    {
        if(c[i].y>n)
        {
            cout<<"No";
            return 0;
        }
    }
    for(i=0;i<=200000;i++) 
    {
        nxt[i]=i+1;
        pre[i]=i-1;
    }
    sort(c+1,c+200001,cmp);
    for(i=1;i<=200000;i++)
    {
        if(c[i].y==0) break;
        t=d[c[i].x];
        u=c[i].x;
        now=0;
        while(t>0&&now<=n)
        {
            now=nxt[now];
            if(now>n) break;
            if(a[now]!=u)
            {
                ans[now]=u;
                pre[nxt[now]]=pre[now];
                nxt[pre[now]]=nxt[now];
                d[u]--;
                t--;
            }
        }
    }
    /*for(i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    for(i=0;i<=n;i++) cout<<nxt[i]<<" ";*/
    now=0;
    for(i=1;i<=200000;i++)
    {
         while(d[i]>0)
         {
             now=nxt[now];
             ans[now]=i;
             d[i]--;
         }
    }
    for(i=1;i<=n;i++)
    {
        if(ans[i]==a[i])
        {
             while(1)
             {
                 t=rand()%n+1;
                 if(ans[t]!=a[i]&&ans[i]!=a[t])
                 {
                     swap(ans[t],ans[i]);
                     break;
                 }
             }
        }
    }         
    cout<<"Yes"<<endl;
    for(i=1;i<=n;i++) cout<<ans[i]<<" ";
    cin>>i;
}
