#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	char a,b;
	scanf("%c %c",&a,&b);
	if(a < b)	printf("<\n");
	else if(a > b)	printf(">\n");
	else printf("=\n");
	return 0;
}
