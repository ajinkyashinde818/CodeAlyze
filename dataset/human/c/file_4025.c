#include<stdio.h>

int main(){
	int a,b,k;
	scanf("%d%d%d",&a,&b,&k);
	int n=a+1;
	for(int i=0;i<k;i++){
		while(1){
			n--;
			if(a%n==0 && b%n==0)break;
		}
	}
	printf("%d\n",n);
	return 0;
}
