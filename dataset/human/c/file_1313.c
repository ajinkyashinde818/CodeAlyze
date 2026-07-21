#include<stdio.h>
int a[200001],b[200001],c[200001];
int main(void)
{
	int n,m,i,f;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) c[i]=0;
	for(i=0;i<m;i++) scanf("%d %d",&a[i],&b[i]);
	for(i=0;i<m;i++){
		if(a[i]==1) c[b[i]]=1;
	}	
	f=0;
	for(i=0;i<m;i++){
		if(c[a[i]]==1&&b[i]==n){
			f=1; break;
		}
	}	
	if(f==1) printf("POSSIBLE\n");
	else printf("IMPOSSIBLE\n");
	return 0;
}
