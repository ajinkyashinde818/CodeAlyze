#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
const int RLEN=1<<18|1;
inline char nc() {
	static char ibuf[RLEN],*ib,*ob;
	(ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
	return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
	char ch=nc(); int i=0,f=1;
	while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
	while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
	return i*f;
}

const int N=1e5+50;
int n,a[N],b[N],step;
int anc[N],vis[N];
map <int,int> s;
set <int> pos[N];
inline void lsh(int *c) {
	vector <int> vec;
	for(int i=1;i<=n+1;i++) vec.push_back(c[i]);
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int i=1;i<=n+1;i++) c[i]=lower_bound(vec.begin(),vec.end(),c[i])-vec.begin()+1; 
} 
inline int ga(int x) {return (anc[x]==x) ? x : (anc[x]=ga(anc[x]));}
inline void merge(int x,int y) {anc[ga(x)]=ga(y);}
int main() {
	n=rd();
	for(int i=1;i<=n;i++) a[i]=rd(), a[n+1]^=a[i], ++s[a[i]]; ++s[a[n+1]];
	for(int i=1;i<=n;i++) b[i]=rd(), b[n+1]^=b[i], --s[b[i]]; --s[b[n+1]];
	for(auto v:s) if(v.second) return puts("-1"),0;
	lsh(a); lsh(b); int m=*max_element(a+1,a+n+2);
	for(int i=1;i<=n+1;i++) 
		if((a[i]^b[i]) || i>n) pos[a[i]].insert(i);
	for(int i=1;i<=m;i++) anc[i]=i;
	for(int i=n+1;i;i--) if(i>n || (a[i]^b[i])){
		if(vis[i]) continue;
		vector <int> vec; 
		for(int j=b[i];;) {
			int nxt=*pos[j].begin();
			pos[j].erase(pos[j].begin());
			vec.push_back(nxt);
			if(nxt==i) break;
			else j=b[nxt];
		}
		for(auto j:vec) merge(b[j],b[i]), vis[j]=1; 
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n+1;i++) if(a[i]^b[i] || i==n+1) {
		if(i<=n) ++step;
		if(!vis[ga(a[i])] && (ga(a[i])==a[i])) vis[ga(a[i])]=1, ++step;
	}
	cout<<step-1<<'\n';
}
