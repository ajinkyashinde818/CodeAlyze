#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <set>
#pragma warning(disable : 4996)

#define N_MAX 100000
#define Q_MAX 200000

char S[Q_MAX+N_MAX+Q_MAX+2];

int main(void) {
	scanf("%s", &S[Q_MAX+1]);
	int len = strlen(&S[Q_MAX + 1]);
	char *s = &S[Q_MAX + 1];//初めの文字
	char *e = &S[Q_MAX + 1 + (len-1)];//終わりの文字
	int Q;
	scanf("%d", &Q);
	bool reverse = false;
	for (int i = 0; i < Q; ++i) {
		int T;
		scanf("%d", &T);
		if (T == 1) {
			reverse = !reverse;
		}
		else {
			int F;
			char c;
			scanf("%d %c", &F, &c);
			if (F == 1) {
				if (reverse == false) {
					--s;
					*s = c;
				}
				else {
					++e;
					*e = c;
				}
			}
			else {
				if (reverse == false) {
					++e;
					*e = c;
				}
				else {
					--s;
					*s = c;
				}
			}
			++len;
		}
	}
	if (reverse == false) {
		char *p = s;
		while (true) {
			printf("%c", *p);
			if (p == e) break;
			p++;
		}
	}
	else {
		char *p = e;
		while (true) {
			printf("%c", *p);
			if (p == s) break;
			p--;
		}
	}

	return 0;
}
