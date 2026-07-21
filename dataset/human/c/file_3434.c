#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(void) {
	char WORDS[4][8] = { "dreamer", "eraser", "dream", "erase" };
	char s[100000];
	scanf("%s", s);
	int sw = TRUE, len;
	len = (int)strlen(s);
	while ((sw) && (s[0] != '\0')) {
		sw = FALSE;
		for (int i = 0; i < 4; i++) {
			int len_of_WORD = (int)strlen(WORDS[i]);
			if (((int)strlen(s) >= len_of_WORD) && (strcmp(s + len - len_of_WORD, WORDS[i]) == 0)) {
				s[len - len_of_WORD] = '\0';
				len = (int)strlen(s);
				sw = TRUE;
				break;
			}
		}
	}
	if (sw) {
		printf("YES\n");
	}
	else if (!sw) {
		printf("NO\n");
	}
	return 0;
}
