#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n;
	int i;
	scanf("%d", &n);

	int *a = (int*)malloc(n * sizeof(int));
	int *b = (int*)malloc(n * sizeof(int));
	b[0] = 1;

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int bsize = 1;
	int k = 0;
	int count = 1;
	int ans = -1;

	while (bsize < n) {
		int d = a[k];
		if (d == 2) {
			ans = 0;
			break;
		}
		else {
			for (int j = 0; j < bsize; j++) {
				if (d == b[j]) {
					ans = -1;
					break;
				}
			}
			b[bsize] = d;
		}
		k = d - 1;
		count++;
		bsize++;
	}

	if (ans == 0)printf("%d\n", count);
	else printf("%d\n", -1);
	return 0;
}
