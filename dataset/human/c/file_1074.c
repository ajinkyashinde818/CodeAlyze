// Aizu 1137: Numeral System
// 2017.9.13 bal4u@uu

#include <stdio.h>
#include <ctype.h>

int tr['z'];
char s[2][20];
int tbl[4][2] = { { 1000, 'm' }, { 100, 'c' }, { 10, 'x' }, { 1, 'i' } };

int main()
{
	int n, i, m, a, ans;
	char *p;
	
	for (i = 0; i < 4; i++) tr[tbl[i][1]] = tbl[i][0]; 
	scanf("%d", &n);
	while (n-- > 0) {
		scanf("%s%s", s[0], s[1]);
		ans = 0;
		for (i = 0; i < 2; i++) {
			for (p = s[i], a = 0; *p; ) {
				m = 1; if (isdigit(*p)) m = *p++ - '0';
				if (tr[*p] > 0) m *= tr[*p++];
				a += m;
			}
			ans += a;
		}
		for (i = 0; i < 4; i++) {
			int k = tbl[i][0];
			if (ans >= k) {
				int t = ans/k; ans %= k; 
				if (t > 1) putchar(t+'0');
				putchar(tbl[i][1]);
			}
		}
		putchar('\n');
	}
	return 0;
}
