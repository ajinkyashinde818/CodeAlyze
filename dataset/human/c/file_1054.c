#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define pai 3.1415926535


int main(void){

	char S[51];
	scanf("%s", S);
	S[strlen(S) - 8] = '\0';
	printf("%s", S);

	return 0;


}
