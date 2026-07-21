#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map> 
using namespace std;
int n,A[110000],B[110000],len,in[210000],ou[210000],w[210000],father[210000];
map<int,int>M;
int findfather(int k1){
	if (father[k1]==k1) return k1; return father[k1]=findfather(father[k1]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<=n;i++) scanf("%d",&B[i]);
	int tot=0;
	for (int i=1;i<=n;i++)
		if (A[i]!=B[i]){
			if (M[A[i]]==0) M[A[i]]=++len,w[len]=A[i];
			if (M[B[i]]==0) M[B[i]]=++len,w[len]=B[i];
			tot++; ou[M[A[i]]]++; in[M[B[i]]]++;
		}
	int where=0;
	for (int i=1;i<=len;i++)
		if (in[i]>ou[i]){
			if (where||in[i]>ou[i]+1){
				printf("-1\n"); return 0;
			}
			where=i;
		}
	int pre=0;
	for (int i=1;i<=n;i++) pre^=A[i];
	if (where&&pre!=w[where]){
		printf("-1\n"); return 0;
	}
	if (where==0&&M[pre]) where=M[pre];
	for (int i=1;i<=len;i++) father[i]=i;
	int num=len;
	for (int i=1;i<=n;i++)
		if (A[i]!=B[i]){
			int k1=M[A[i]],k2=M[B[i]];
			if (findfather(k1)!=findfather(k2)){
				num--; father[findfather(k1)]=findfather(k2);
			}
		}
	int ans=tot+num-(where>0);
	cout<<ans<<endl;
	return 0;
}
