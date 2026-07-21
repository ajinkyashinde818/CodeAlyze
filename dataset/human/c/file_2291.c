#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//絶対値
long long int change_plus(long long int a) {
	if (a < 0) { return -a; }
	if (a >= 0) { return a; }
}
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

int main() {
	long long int n, m, k = 0;
	char str[15],str2[15],str3[15];
	scanf("%lld",&n);
	if (n < 1200) { printf("ABC"); }
	else {
		printf("ARC");
	}
}
