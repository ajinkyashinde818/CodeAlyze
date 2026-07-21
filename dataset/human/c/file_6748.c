#include<stdio.h>
int a[10000],b[10000];
int main(){
	int n,m,i,f;
	int fr[501];
	while(1){
		for(i=0;i<=500;i++){
			fr[i]=0;
			f=0;
		}
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)break;
		for(i=1;i<=m;i++)scanf("%d%d",&a[i],&b[i]);
		for(i=1;i<=m;i++){
			if(a[i]==1){
				fr[b[i]]=1;
			}
			else if(b[i]==1){
				fr[a[i]]=1;
			}
		}
		for(i=1;i<=m;i++){
			if(fr[a[i]]==0 && fr[b[i]]==1)fr[a[i]]=2;
			if(fr[a[i]]==1 && fr[b[i]]==0)fr[b[i]]=2;
		}
		for(i=2;i<=500;i++){
			if(fr[i])f++;
		}
		printf("%d\n",f);
	}
	return 0;
}
