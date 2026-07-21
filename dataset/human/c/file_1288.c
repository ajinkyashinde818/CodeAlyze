// Aizu Vol-0 0082: Flying Jenny
// 2017.8.4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *gets(char *);
char buf[200], *p;

int getInt(void)
{
	int n = 0;
	while (isspace(*p)) p++;
	while (isdigit(*p)) n = 10 * n + (*p++ - '0');
	return n;
}

int h[16] = { 4,1,4,1,2,1,2,1,4,1,4,1,2,1,2,1 };
int d[8] = { 41412121, 14121214, 41212141, 12121414, 21214141, 12141412, 21414121, 14141212 };
char *ans[8] = {
	"4 1 4 1 2 1 2 1", "1 4 1 2 1 2 1 4", "4 1 2 1 2 1 4 1", "1 2 1 2 1 4 1 4",
	"2 1 2 1 4 1 4 1", "1 2 1 4 1 4 1 2", "2 1 4 1 4 1 2 1", "1 4 1 4 1 2 1 2" };

int main()
{
	int i, j, c, id, max, m[8];
	int *hp, *hh;

	while (gets(p = buf) != NULL) {
		for (i = 0; i < 8; i++) m[i] = getInt();
		max = 0, id = 3;
		for (i = 0, hp = h; i < 8; i++, hp++) {
			for (j = 0, c = 0, hh = hp; j < 8; j++, hh++) {
				if (m[j] >= *hh) c += *hh;
				else c += m[j];
			}
			if (max < c) max = c, id = i;
			else if (max == c && d[id] > d[i]) id = i;
		}
		//		printf("max %d, id %d, C %d\n", max, id, d[id]);
		puts(ans[id]);
	}
	return 0;
}
