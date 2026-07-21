#define _CRT_SECURE_NO_WARNINGS
////#define _USE_MATH_DEFINES
#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
//#include<time.h>
#define P(type,x) fprintf(stdout,"%"#type"\n",x)

int main() {
	int stone, n, a;
	fscanf(stdin, "%d", &a);
	while (a--) {
		fscanf(stdin, "%d%d", &stone, &n);
		if (!(stone%n)&1)P(d, n);
		else P(d, stone%n);
	}
	return 0;
}
