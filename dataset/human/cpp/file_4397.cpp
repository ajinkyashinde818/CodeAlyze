#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
const int N=200010;
map <int,int> w;
int a[N],b[N],fa[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
int main() {
    int n,ans=0,tt=0;
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=gi(),a[0]^=a[i],fa[i]=i;
    for(int i=1;i<=n;i++) b[i]=gi(),b[0]^=b[i];
    for(int i=0;i<=n;i++)
	if(!i||a[i]!=b[i]) {
	    if(i) ++ans;
	    if(!w[a[i]]) w[a[i]]=++tt,fa[tt]=tt;
	    if(!w[b[i]]) w[b[i]]=++tt,fa[tt]=tt;
	    fa[find(w[a[i]])]=find(w[b[i]]);
	}
    for(int i=1;i<=tt;i++)
	if(fa[i]==i) ++ans;
    sort(a,a+n+1),sort(b,b+n+1);
    for(int i=0;i<=n;i++)
	if(a[i]!=b[i]) return puts("-1"),0;
    cout<<ans-1;
    return 0;
}
