#include <stdio.h>

long retans(long a, long b, long c){
	if(a + b + 1 >= c)	return b + c;
	else return b + (a + b + 1);
}

int main(int argc, char const *argv[]){
	long a,b,c;
	scanf("%ld %ld %ld",&a,&b,&c);
	printf("%ld\n", retans(a,b,c));
	return 0;
}
