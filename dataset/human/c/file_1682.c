#include <stdio.h>
#include <string.h>

int main() {
	int n, lst = 0, nxt, sum = 0;
	bool add[25];
	scanf("%d", &n);
	memset(add, false, sizeof add);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nxt);
		if (lst == nxt - 1)
			add[lst] = true;
		lst = nxt;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &nxt);
		sum += nxt;
	}
	for (int i = 1; i < n; i++) {
		scanf("%d", &nxt);
		if (add[i])
			sum += nxt;
	}
	printf("%d\n", sum);
	return 0;
}
