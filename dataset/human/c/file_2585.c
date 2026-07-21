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
	scanf("%s", str);

	if (str[0] == 'a') { a++; }

	if (str[1] == 'a') { a++; }
	
	if (str[2] == 'a') { a++; }
	
	if (str[0] == 'b') { b++; }

	if (str[1] == 'b') { b++; }

	if (str[2] == 'b') { b++; }

	if (str[0] == 'c') { c++; }

	if (str[1] == 'c') { c++; }

	if (str[2] == 'c') { c++; }

	if (a == 1 && b == 1 && c == 1) { printf("Yes"); }
	else { printf("No"); }
	
	
}
