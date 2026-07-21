#include <stdio.h>
int main(void){
	int i,k,n,m,a[100],tmp;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(k=1;k<=m;k++){
		for(i=0;i<n-1;i++){
			if((a[i]%k)>(a[i+1]%k)){
				tmp=a[i];
				a[i]=a[i+1];
				a[i+1]=tmp;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
	return 0;
}
