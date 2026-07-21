#include <stdio.h>
#include <math.h>
#include <string.h>
#define inf 1000000007;
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
	int a,b,c,i,j,k;
	char x,y;
	scanf("%c %c",&x,&y);
	a=x-'0';
	b=y-'0';
	if (a>b) printf(">\n");
	if (a==b) printf("=\n");
	if (a<b) printf("<\n");
	return 0;
}
