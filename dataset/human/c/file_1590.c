// 再提出

#include <stdio.h>
 
char s[100001];
 
int main(void) {
	int len;
 
	scanf("%s%n", s, &len);
 
	int ans = 0;
	for (int l = 0, r = len - 1; l <= r; ) {
		if (s[l] == s[r]) {
			l++;
			r--;
		} else if (s[l] == 'x') {
			l++;
			ans++;
		} else if (s[r] == 'x') {
			r--;
			ans++;
		} else {
			puts("-1");
			return 0;
		}
	}
 
	printf("%d\n", ans);
 
	return 0;
}
