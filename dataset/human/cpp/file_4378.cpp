#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int tot,n,a[N],b[N],ans,A[N],B[N],f[N];
int ef(int x){
	int l=1,r=tot;
	while (l<r){
		int mid=(l+r)/2;
		if (A[mid]<x)l=mid+1;
		else r=mid;
	}
	return l;
}
int find(int x){
	if (x==f[x])return x;
	return f[x]=find(f[x]);
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)scanf("%d",&a[i]),a[n]^=a[i];
	for (int i=0;i<n;i++)scanf("%d",&b[i]),b[n]^=b[i];
	int flag=1;
	for (int i=0;i<n;i++)
		if (a[i]!=b[i])flag=0;
	if (flag){
		puts("0");
		return 0;
	}	
	for (int i=0;i<=n;i++)A[i]=a[i],B[i]=b[i];
	sort(A,A+n+1);sort(B,B+n+1);
	for (int i=0;i<=n;i++)
		if (A[i]!=B[i]){
			puts("-1");
			return 0;
		}
	tot=0;	
	for (int i=0;i<=n;i++)
		if (a[i]!=b[i]||i==n){
			A[++tot]=a[i];
			A[++tot]=b[i];
			if (i<n)ans++;
		}	
	sort(A+1,A+tot+1);
	int num=1;
	for (int i=2;i<=tot;i++)
		if (A[i]!=A[num])A[++num]=A[i];
	tot=num;ans+=num;ans--;
	for (int i=1;i<=num;i++)f[i]=i;
	for (int i=0;i<=n;i++)
		if (a[i]!=b[i]){
			int k1=ef(a[i]),k2=ef(b[i]);
			if (find(k1)!=find(k2))f[find(k1)]=find(k2),ans--;
		}
	printf("%d\n",ans);	
	return 0;	
}
