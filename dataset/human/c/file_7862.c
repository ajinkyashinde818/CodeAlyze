#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES
#include<stdio.h>
#include<stdlib.h>
//#include<math.h>
//#include<string.h>
//#include<time.h>
//#include<ctype.h>
//#define pi acos(-1.0)
#define P(type,x) fprintf(stdout,"%"#type"\n",x)
#define S(type,x) fscanf(stdin,"%"#type,&x)
int comp(const void*a, const void*b) {
	return *(int*)a - *(int*)b;
}
int main(){
	int v, d;
	while (~fscanf(stdin, "%d%d", &v, &d)) {
		int c=1,i=2;
		int fib[1001] = { 1,2 };
		for (; i <=v ; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % 1001;
		qsort(fib, v+1, sizeof(int), comp);
		for (i = 2; i <= v; i++)
			if (fib[i] - fib[i - 1] >= d) c++;
		P(d, c);
	}
	return 0;
}
