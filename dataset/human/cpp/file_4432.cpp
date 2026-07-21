#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
const int N=100005;
int n;
int a[N],b[N],A[N],B[N];
map <int,int> Map;
int fa[N],cnt[N];
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void Merge(int x,int y){
	fa[getf(x)]=getf(y);
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),a[n+1]^=a[i];
	for (int i=1;i<=n;i++)
		b[i]=read(),b[n+1]^=b[i];
	for (int i=1;i<=n+1;i++){
		A[i]=a[i];
		B[i]=b[i];
	}
	sort(A+1,A+n+2);
	sort(B+1,B+n+2);
	for (int i=1;i<=n+1;i++)
		if (A[i]!=B[i])
			return puts("-1"),0;
	int _n=0;
	for (int i=1;i<=n;i++)
		if (a[i]!=b[i])
			_n++,a[_n]=a[i],b[_n]=b[i];
	a[_n+1]=a[n+1],b[_n+1]=b[n+1];
	n=_n;
	int m=0;
	for (int i=1;i<=n+1;i++)
		a[i]=Map[a[i]]?Map[a[i]]:Map[a[i]]=++m;
	for (int i=1;i<=n+1;i++)
		b[i]=Map[b[i]];
	for (int i=1;i<=m;i++)
		fa[i]=i;
	for (int i=1;i<=n+1;i++)
		Merge(b[i],a[i]);
	for (int i=1;i<=m;i++)
		cnt[getf(i)]++;
	int ans=n-1;
	for (int i=1;i<=m;i++)
		if (cnt[i])
			ans++;
	printf("%d",ans);
	return 0;
}
