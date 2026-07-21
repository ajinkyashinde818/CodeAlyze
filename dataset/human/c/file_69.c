#include <stdio.h>

#define max 3001

int main(void)
{
	int r,g,b,n;
	
	scanf("%d %d %d %d",&r,&g,&b,&n);
	
	int i,j,count = 0;
	
	
	
	for(i = 0;i < max ;i++){
		for(j = 0;j < max;j++){
			int remain = n - (r*i+g*j);
			if(remain < 0){
				break;
			}
			if(remain % b == 0 || remain == 0){
				count = count + 1;
			}
			
		}
	}
	
	printf("%d\n",count);
	
	return 0;
	
}
