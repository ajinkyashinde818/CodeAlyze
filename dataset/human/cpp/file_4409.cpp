#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int N=1e6+5;
typedef long long ll;
int a[N],a1[N];
int b[N],b1[N];
int n,cnt;
map<int,int>z;
int fa[N],sz[N];
int find_father(int x){
    if(fa[x]==x)
        return x;
    return fa[x]=find_father(fa[x]);
}
void Merge(int x,int y){
    int f1=find_father(x),f2=find_father(y);
    if(f1==f2)
        return ;
    fa[f1]=f2;
    sz[f2]+=sz[f1];
    return ;
}
int main()
{
    scanf("%d",&n);
    int x=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        x^=a[i];
    }
    a[n+1]=x;
    x=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        x^=b[i];
    }
    b[++n]=x;
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){
            flag=false;
        }
        a1[i]=a[i];
        b1[i]=b[i];
    }
    if(flag){
        puts("0");
        return 0;
    }
    sort(a1+1,a1+n+1);
    sort(b1+1,b1+n+1);
    for(int i=1;i<=n;i++){
        if(a1[i]!=b1[i]){
            puts("-1");
            return 0;
        }
        if(z.find(a1[i])==z.end())
            z[a1[i]]=++cnt;
    }
    for(int i=1;i<=cnt;i++)
        fa[i]=i,sz[i]=1;
    for(int i=1;i<=n;i++){
        a[i]=z[a[i]];
        b[i]=z[b[i]];
    }
    int ans=0;
    for(int i=1;i<n;i++){
        if(a[i]!=b[i]){
            ans++;
            Merge(a[i],b[i]);
        }
    }
    ans+=find_father(a[n])==a[n]&&sz[a[n]]==1;
    for(int i=1;i<=cnt;i++){
        if(find_father(i)==i&&sz[i]>1)
            ans++;
    }
    ans--;
    printf("%d\n",ans);
}
