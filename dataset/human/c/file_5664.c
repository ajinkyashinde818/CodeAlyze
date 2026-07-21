#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
	long long int x;
	long long int per,sla;
	scanf("%lld",&x);
	sla=x/11;
	per=x%11;
	sla*=2;
	if(per==0) sla+=0;
	else if(per<=6) sla++;
	else sla+=2;
	printf("%lld\n",sla);
	
	return 0;
}
