#include <stdio.h>
#define N 1500000
int book[50];
int dan(int k, int n) {
	int num = 0;
	int ans = 1;
	int i;
	for(i = 0; i < n; ++ i) {
		if(book[i] > k) return 0;
		if(num + book[i] > k) {
			ans ++;
			num = book[i];
		} else {
			num += book[i];
		}
	}
	return ans;
}
int main() {
	int m, n;
	int i;
	while(1) {
		scanf("%d %d", &m, &n);
		if(m == 0 && n == 0) break;
		for(i = 0; i < n; ++ i) scanf("%d", &book[i]);
		int left = 0, right = N;
		while(right - left > 1) {
			int ind = (left + right) / 2;
			if(dan(ind, n) > m || dan(ind, n) == 0) {
				left = ind;
			} else {
				right = ind;
			}
		}
		int ans;
		if(dan(left, n) > m || dan(left, n) == 0) ans = right;
		else ans = left;
		printf("%d\n", ans);
	}
	return 0;
}
