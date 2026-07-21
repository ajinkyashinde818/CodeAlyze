#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100100;
int i,j,k,n,m,ch,ff,nls,ans;
int A[N],B[N],a[N],b[N],Ls[N],f[N],z[N];
void R(int &x) {
	ff=x=0;
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
int getf(int x) {
	if (f[x]==x) return x;
	return f[x]=getf(f[x]);
}
int find(int x) {
	int l=1,r=nls,mid;
	while (l<r) {
		mid=(l+r)>>1;
		if (Ls[mid]==x) return mid;
		if (Ls[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main() {
	R(n);n++;
	for (i=1;i<n;i++) {
		R(A[i]);
		a[i]=A[i];
		A[n]^=A[i];
	}
	a[n]=A[n];
	for (i=1;i<n;i++) {
		R(B[i]);
		b[i]=B[i];
		B[n]^=B[i];
	}
	b[n]=B[n];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for (i=1;i<=n;i++) if (a[i]!=b[i]) return puts("-1"),0;
	a[n+1]=-1;
	for (i=1;i<=n;i++) if (a[i]!=a[i+1]) Ls[++nls]=a[i];
	for (i=1;i<=n;i++) A[i]=find(A[i]),B[i]=find(B[i]);
	for (i=1;i<=nls;i++) f[i]=i;
	for (i=1;i<n;i++) if (A[n]==B[i]) ans=-1;
	ans+=n-1;
	for (i=1;i<n;i++) {
		if (A[i]!=B[i]) {
			z[A[i]]=z[B[i]]=1;
			if (getf(A[i])!=getf(B[i])) f[f[A[i]]]=f[B[i]];
		}
		else ans--;
	} 
	for (i=1;i<=nls;i++) if (getf(i)==i && z[i]) ans++;
	printf("%d\n",max(0,ans));
}
