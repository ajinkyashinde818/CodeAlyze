#include<stdio.h>
int main(void){
	int n,d,x,i,sum=0;
	scanf("%d %d %d",&n,&d,&x);
	int a[101];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		int j=1;
		while(j<=d){sum++;j+=a[i];}
	}
	printf("%d",sum+x);
	return 0;
}
