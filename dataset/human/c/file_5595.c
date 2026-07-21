#include <stdio.h>
 
int main(){
	long long int x,i,j,rem=0;
	scanf("%lld",&x);
	i = x/11;
	j = x%11;
	if(j>6){
	rem = rem + 2; 
	}else{
	rem = rem + 1;
	}
	if(j == 0){
	rem = 0;
	}
	x = i*2 + rem;
	printf("%lld",x);
	return 0;
	}
