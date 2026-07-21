#include <stdio.h>
#include <string.h>
int main() {
	char a[100010];
	int ans = 0, len;
	int l = 0, r = 1;
	scanf("%s", a);
	len = strlen(a);
	for (; l <= len - r; l++,r++)
	{

		if (a[l] != a[len - r]) {
			if (a[l] == 'x') {
				r--;
				ans++;
			}
			else if (a[len - r] == 'x') {
				l--;
				ans++;
			}
			else {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
