#include <stdio.h>
#include <string.h>
char first[200000];
char last[200000];
int main() {
	char s[100001], c;
	int q, t, f, turn = 0;
	int fNum = 0, lNum = 0;
	scanf("%s", s);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &t);
		if (t == 1) {
			// turn 0:普通,1:逆
			turn ^= 1;
		} else {
			scanf("%d %c", &f, &c);
			if ((f == 1 && turn == 0) || (f == 2 && turn == 1)) {
				first[fNum] = c;
				fNum++;
			} else {
				last[lNum] = c;
				lNum++;
			}
		}
	}
	if (turn == 0) {
		for (int i = fNum - 1; i >= 0; i--) {
			printf("%c", first[i]);
		}
		printf("%s%s", s, last);
	} else {
		for (int i = lNum - 1; i >= 0; i--) {
			printf("%c", last[i]);
		}
		for (int i = strlen(s) - 1; i >= 0; i--) {
			printf("%c", s[i]);
		}
		printf("%s", first);
	}
	return 0;
}
