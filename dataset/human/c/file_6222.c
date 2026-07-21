#include<stdio.h>
#include<string.h>
#include<math.h>
#define anD &&
#define oR ||
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define rep(i,n) for((i)=0;(i)<(n);(i)++)

int main(void) {
	int n, i, tmp,b;
	int min, idx, max = -214;
	scanf("%d", &n);
	scanf("%d", &tmp);
	min = idx = tmp;
	for (i = 1; i < n; i++) {
		scanf("%d",&tmp);
		idx = tmp;
		b = idx - min;
		if (tmp < min) min = tmp;

		if (n == 2 oR b > max) max = b;
	}
	printf("%d\n" , max);
	return 0;
}
