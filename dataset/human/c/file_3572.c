#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES
#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
#define P(type,x) fprintf(stdout,"%"#type"\n",x)
int main() {
	int a, s = 0, i = 10;
	while (i--)
		fscanf(stdin, "%d", &a), s += a;
	P(d, s);
	return 0;
}
