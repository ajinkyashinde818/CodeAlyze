#include <stdio.h>
#include <string.h>
int n, m, d[100005];
char s[100005];
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	d[0] = 1;
	for (int i = 5; i <= n; i++) {
		if (d[i - 5] && s[i - 4] == 'd' && s[i - 3] == 'r' && s[i - 2] == 'e' && s[i - 1] == 'a' && s[i] == 'm') d[i] = 1;
		if (d[i - 5] && s[i - 4] == 'e' && s[i - 3] == 'r' && s[i - 2] == 'a' && s[i - 1] == 's' && s[i] == 'e') d[i] = 1;
		if (d[i - 7] && s[i - 6] == 'd' && s[i - 5] == 'r' && s[i - 4] == 'e' && s[i - 3] == 'a' && s[i - 2] == 'm' && s[i - 1] == 'e' && s[i] == 'r') d[i] = 1;
		if (d[i - 6] && s[i - 5] == 'e' && s[i - 4] == 'r' && s[i - 3] == 'a' && s[i - 2] == 's' && s[i - 1] == 'e' && s[i] == 'r') d[i] = 1;
	}
	if (d[n]) puts("YES");
	else puts("NO");
}
