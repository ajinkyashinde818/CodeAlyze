#include <stdio.h>

int min(int a,int b)
{
	if(a > b){
		return b;
	}else{
		return a;
	}
}

int main(void)
{
	int a,b,k;
	
	scanf("%d %d %d",&a,&b,&k);
	
	int i,count = 0;
	
	for(i = min(a,b); i > 1; i--){
		if(a % i == 0 && b % i == 0){
			count = count + 1;
		}
		if(count == k){
			break;
		}
	}
	
	printf("%d\n",i);
	
	return 0;
	
}
