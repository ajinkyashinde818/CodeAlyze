#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p, const void* q) {
	return *(int*)p - *(int*)q;
}

int main(){
	int	n, m;
	int from[200000] = { 0 }, to[200000] = { 0 };
	int a, b, cnt_a = 0, cnt_b = 0;
	int flag = 0;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (a == 1)from[cnt_a] = b, cnt_a++;
		else if (b == n)to[cnt_b] = a, cnt_b++;
	}
	qsort(from, cnt_a, sizeof(int), cmp);
	qsort(to, cnt_b, sizeof(int), cmp);

	int left = 0;
	for (int i = 0; i < cnt_a; i++) {
		for (int j = left; j < cnt_b; j++) {
			//printf("j=%d\n",j);
			if (from[i] == to[j]) {
				flag = 1;
				break;
			}
			else if (from[i] < to[j]) {
				left = j;
				break;
			}
			else if (j == cnt_b - 1) {
				flag = 2;
				break;
			}
		}
		//printf("flag=%d\n", flag);
		if (flag)break;
	}
	if (flag==1)printf("POSSIBLE");
	else printf("IMPOSSIBLE");
	return 0;
}
