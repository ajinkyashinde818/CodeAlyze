#include<stdio.h>
#include<math.h>
#define max(a,b) ((a)>(b)?(a):(b))

int w[100];
int m, n;

int func(int h) {
	int i=0, sum = 0,count=0;
	while(i<n && count < m){
		if (h >= sum + w[i]) 
			sum += w[i++];
		else {
			sum = 0;
			count++;
        }
	}
	return i == n && count < m;
}

int binsearch_func(int low, int hight) {
	int i;
	for (i = 0; i < 100; i++) {
		int mid = (low + hight) / 2;
		int midval = func(mid);

		if (midval)hight = mid;
		else low = mid;
	}
	return max(low,hight);
}

int main(void)
{
	int sum;
	int i;
	while (1) {
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0)break;
		sum = 0;
		for (i = 0; i < n; i++) {
			scanf("%d",&w[i]);
			sum += w[i];
		}
		printf("%d\n", binsearch_func(0, 10000000));
	}
	return 0;
}
