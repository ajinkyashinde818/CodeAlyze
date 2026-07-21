// AOJ 2583: JAG-channel
// 2017.10.6 bal4u@uu
// 2017.11.24

#include <stdio.h>
#include <stdlib.h>

char s[1002][2000];

int main()
{
	int n, i, j, k;
	char buf[10], *p;

	while (fgets(buf, 10, stdin) && *buf != '0') {
		n = atoi(buf);
		for (i = 0; i < n; i++) {
			fgets(p=s[i], 2000, stdin);
			while (*p == '.') *p++ = ' ';
			if (--p >= s[i]) {
				*p = '+', k = p - s[i];
				for (j = i-1; s[j][k] == ' '; j--) s[j][k] = '|';
			}
		}
		for (i = 0; i < n; i++) printf(s[i]);
	}
    return 0;
}
