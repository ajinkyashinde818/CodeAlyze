#include<stdio.h>
int main(void) {
	int n;
	scanf("%d",&n);
	int i,k[100],p[100];
	for(i=0;i<n;i++){
		scanf("%d %d",&k[i],&p[i]);
	}
	int a[100];
	for(i=0;i<n;i++){
		a[i]=k[i]%p[i];
		if(a[i]!=0){
		    printf("%d\n",a[i]);
		}
		else{
		    printf("%d\n",p[i]);
		}
	}
	return 0;
}
