#include <stdio.h>

int	main(void)
{
  	long long int	a;
  	long long int	b;
  	int	num;
  	long long int	x;
  	long long int	r;
  	long long int   l;
  	long long int   tmp;
  
  	num = scanf("%lld %lld", &a, &b);
  	if (num != 2)
    	return (0);
  
	x = a * b;
 
	if (a < b)
    {
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
  
	l = x / b;
  	printf("%lld", l);
 	return (0);
}
