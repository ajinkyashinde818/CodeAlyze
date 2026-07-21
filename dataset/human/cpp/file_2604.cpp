#include<stdio.h>
#include<algorithm>
#include<functional>
#include<cmath>
using namespace std;
int main(void)
{
	int N,count=0;
	long long int a[100010];
	long long int min,sum=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
		if (a[i] < 0) {
			count++;
		}
		if (i == 0) {
			min = abs(a[i]);
		}
		if (abs(a[i]) < min) {
			min = abs(a[i]);
		}
		sum += abs(a[i]);
	}
	if (count % 2 == 0) {
		printf("%lld", sum);
		return 0;
	}
	else {
		printf("%lld", sum - 2*min);
		return 0;
	}
	return 0;
}
