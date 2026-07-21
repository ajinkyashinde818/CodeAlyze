#include<stdio.h>

int main(void){
	
	int i,k,p;
	int dev;
	
	scanf("%d",&i);
	
	while(i > 0){
		
		scanf(" %d %d",&k,&p);
		
		dev = k % p;
		
		if(dev == 0){
			dev = p;
		}
		
		printf("%d\n",dev);
		
		i--;
	}
	
	return(0);
}
