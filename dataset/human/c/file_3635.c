#include<stdio.h>
int main(void){
	
	unsigned long long int a,b,r,tmp,x;
	
	scanf("%lld %lld", &a, &b);
	
	x=a*b;
	
	if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
 
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }

	
	printf("%lld\n",x/b);
	return 0;
}
