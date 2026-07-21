#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int a,b,k;
	int v[100],p = 0;
	scanf("%d%d%d",&a,&b,&k);
	for (int i = 1; i <= ((a < b) ? a : b); ++i){
		if(!(a % i) && !(b % i))	v[p++] = i;
	}
	printf("%d\n",v[p - k]);
}
