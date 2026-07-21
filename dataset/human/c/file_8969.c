#include <stdio.h>

int main(void){
	int t,a;
	
	while(1){
	
	scanf("%d",&a);
		if(a==0){
			return 0;
		}
	
	for(t=0;a!=1;t++){
		if(a%2==0){
			a=a/2;
		}
		else if(a%2==1){
			a=a*3+1;
		}
	}
	
		printf("%d\n",t);
	}
	
		
	return 0;
}
