#include<stdio.h>

int main(){
	int a,n;
	int count=0;
	scanf("%d",&a);
	n=a;
	while(a!=0){
		while(n!=1){
			if(n%2==0){
				n/=2;
			}else {
				n*=3;
				n++;
			}
			count++;
		}
		printf("%d\n",count);
		scanf("%d",&a);
		n=a;
		count=0;
	}
	return 0;
}
