/*
 * main.c
 *
 *  Created on: 2019/07/21
 *      Author: family
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef long long int ll;
int main()
{
	ll a = 0, b = 0, tmp = 0, r = 0, x = 0;
	scanf("%lld %lld", &a, &b);
	x = a * b;
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
    printf("%lld\n", x/b);
    return 0;
}
