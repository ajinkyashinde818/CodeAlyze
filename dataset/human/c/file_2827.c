#include<stdio.h>


int main(void){
	
	int k,s;
	int count=0;
	
	
	scanf("%d  %d ",&k,&s);
	for(int x=0;x<=k;x++){
						
			for(int y=0;y<=k;y++){
				int z=s-x-y;
								if(0<=z &&  z<=k)
									count++;
			}
	}
	printf("%d  \n",count);
	
	return 0;
}
