#include <bits/stdc++.h>
using namespace std;

const long INF = 1L << 60;

int a[200010];

int main(){
	int n;
	scanf("%d", &n);
	long sum = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
		sum += a[i];
	}
	long ans = INF, temp = 0;
	for(int i = 0; i < n - 1; i++) {
		temp += a[i];
		ans = min(ans, abs(2 * temp - sum));
	}
	printf("%ld\n", ans);
}
