#include<stdio.h>
int main(){
	int a,b,k;
	int m=0;
	int i;
	int j,l;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&k);
	for(i=100;i>0;i--){
		j=a%i;
		l=b%i;
		if(j==0&&l==0)m++;
		if(m==k){
			printf("%d",i);
			break;
		}
	}
	return 0;
}
