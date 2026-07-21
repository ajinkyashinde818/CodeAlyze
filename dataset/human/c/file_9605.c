#include <stdio.h>

int main(void){

  int n,d,x;
  scanf("%d %d %d", &n, &d, &x);
  int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int sum = x;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= d; j += a[i]) {
			sum++;
		}
	}
	printf("%d\n", sum);

  return 0;
}
