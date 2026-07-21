#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int n,a[N],b[N],c[N],d[N],fa[N],st[N],tp=0;
int getf(int x) {
    return x==fa[x]?x:fa[x]=getf(fa[x]);
}
int main() {
    n=gi();
    int sum=0;
    for(int i=1;i<=n;i++) a[i]=gi(),sum^=a[i];
    a[n+1]=sum;sum=0;
    for(int i=1;i<=n;i++) b[i]=gi(),sum^=b[i];
    b[n+1]=sum;
    ++n;
    for(int i=1;i<=n;i++) c[i]=a[i],d[i]=b[i];
    sort(c+1,c+n+1),sort(d+1,d+n+1);
    for(int i=1;i<=n;i++) if(c[i]!=d[i]) return puts("-1"),0;
    int ans=0;
    for(int i=1;i<=n;i++)
        if(a[i]!=b[i]||i==n) {
            st[++tp]=a[i],st[++tp]=b[i];
            if(i<n) ++ans;
        }
    sort(st+1,st+tp+1);
    tp=unique(st+1,st+tp+1)-st-1;
    for(int i=1;i<=tp;i++) fa[i]=i;
    for(int i=1;i<n;i++) {
        a[i]=lower_bound(st+1,st+tp+1,a[i])-st;
        b[i]=lower_bound(st+1,st+tp+1,b[i])-st;
        fa[getf(a[i])]=getf(b[i]);
    }
    for(int i=1;i<=tp;i++) if(getf(i)==i) ++ans;
    printf("%d\n",ans-1);
    return 0;
}
