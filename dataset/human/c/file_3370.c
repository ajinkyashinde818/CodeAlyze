#include <stdio.h>
#include <string.h>

char *tbl[] = {"dream", "erase", "dreamer", "eraser"};
int len[] = {5, 5, 7, 6};
char str[100001];

int main() {
	int i;
	int pos;

	scanf("%s", str);
	pos = strlen(str);


	while(pos > 0) {
		for(i = 0; i < 4; i++) {
			if(pos >= len[i] && strcmp(tbl[i], &str[pos - len[i]]) == 0) {
				str[pos - len[i]] = '\0';
				break;
			}
		}
		if(i == 4) {
			printf("NO\n");
			return 0;
		}
		pos -= len[i];
	}

	printf("YES\n");

	return 0;

}
