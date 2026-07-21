#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//大小比較(大)
long long int big(long long int a, long long int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

//大小比較(小)
long long int small(long long int a, long long int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}

main() {
	long long int a=0,b=0,c=0,n, m, k = 0;
	char str[5];
	char x, y;
	scanf("%c %c", &x,&y);
	a=(long long int)x;
    b=(long long int)y;
	if (a < b) { printf("<"); }
	if (a == b) { printf("="); }
	if (a > b) { printf(">"); }
	
}
