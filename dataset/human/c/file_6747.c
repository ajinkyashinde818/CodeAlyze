#include<stdio.h>
int a[10000],b[10000];
int main(void)
{
	int n,m,f[501]={0},z,i;
	scanf("%d",&n);
	scanf("%d",&m);
        while(n!=0&&m!=0){
	for(i=0;i<501;i++){
        f[i]=0;
        z=0;
	}
	for(i=0;i<m;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	for(i=0;i<m;i++){
	if(1==a[i]){
		f[b[i]]=1;
		f[a[i]]=1;
		z=z+1;
	}
	}
	for(i=0;i<m;i++){
	if(f[a[i]]==1 && f[b[i]]==0){
		f[b[i]]=2;
		z=z+1;
	}
	if(f[a[i]]==0 && f[b[i]]==1){
		f[a[i]]=2;
		z=z+1;
	}
	}
	printf("%d\n",z);
scanf("%d %d",&n,&m);
}
	return 0;
}
