#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES
#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
#include<string.h>
//#include<time.h>
//#define pi acos(-1.0)
#define P(type,x) fprintf(stdout,"%"#type"\n",x)

int main() {
	int n, m, i;
	fscanf(stdin, "%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		if (i) fprintf(stdout, " ");
		if (i <= n / 2) fprintf(stdout, "%d", 0);
		else fprintf(stdout, "%d", m);
	}
	puts("");
	return 0;
}
