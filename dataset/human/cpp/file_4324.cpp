#include <bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int gi(){
    char ch=getchar(); int x=0,q=0;
    while(ch<'0'||ch>'9') q=ch=='-'?1:q,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return q?-x:x;
}
int a[N],b[N],c[N],d[N],f[N],p,ans;
map<int,int>fa;
int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
    int n=gi(),s=0;
    for (int i=1; i<=n; ++i)
	c[i]=a[i]=gi(),s^=a[i];
    c[n+1]=a[n+1]=s,s=0;
    for (int i=1; i<=n; ++i)
	d[i]=b[i]=gi(),s^=b[i];
    ++n,d[n]=a[n]=s;
    sort(c+1,c+n+1);
    sort(d+1,d+n+1);
    for (int i=1; i<=n; ++i)
	if (c[i]!=d[i])
	    return puts("-1"),0;
    for (int i=1; i<=n; ++i){
	if (a[i]!=b[i]&&i!=n) ++ans;
	if (i==n&&ans==0){
	    cout<<0; return 0;
	}
	if (a[i]!=b[i]||i==n){
	    if (!fa[a[i]]) fa[a[i]]=++p;
	    if (!fa[b[i]]) fa[b[i]]=++p;
	}
    }
    for (int i=1; i<=p; ++i) f[i]=i;
    for (int i=1; i<=n; ++i)
	if (a[i]!=b[i])
	    f[find(fa[a[i]])]=find(fa[b[i]]);
    for (int i=1; i<=p; ++i)
	if (find(i)==i)
	    ++ans;
    cout<<ans-1;
    return 0;
}
