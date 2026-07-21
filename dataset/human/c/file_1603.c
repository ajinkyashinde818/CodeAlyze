#include <stdio.h>
#include <stdlib.h>

int main()
{
	char s[100001];
	scanf("%s", s);
	
	int i, j, k = 0, flag = 1, count[100001] = {};
	for (i = -1, j = 0; s[j] != 0; j++);
	while (i < j) {
		for (i++; i < j && s[i] == 'x'; i++) count[k]++;
		if (i == j) {
			count[k] = 0;
			break;
		} else {
			for (j--; s[j] == 'x'; j--) count[k]--;
			if (j == i) break;
			else if (s[j] == s[i]) k++;
			else {
				flag = 0;
				break;
			}
		}
	}
	
	int sum = 0;
	for (i = 0; i <= k; i++) sum += abs(count[i]);
	
	if (flag == 0) printf("-1\n");
	else printf("%d\n", sum);
	fflush(stdout);
	return 0;
}
