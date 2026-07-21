#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long ll;

int main()
{
	int i, j;
	char s[101], t[101], tmp;
	scanf("%s %s", s, t);

	for (i = 0; i < strlen(s) - 1; i++) {
		for (j = i + 1; j < strlen(s); j++) {
			if (s[i] > s[j]) {
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
	}
	for (i = 0; i < strlen(t) - 1; i++) {
		for (j = i + 1; j < strlen(t); j++) {
			if (t[i] < t[j]) {
				tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			}
		}
	}
	if (strcmp(s, t) < 0) {
        puts("Yes");
    } else {
        puts("No");
    }

	return 0;
}
