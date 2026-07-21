#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char S[100001];
char *tbl[] = { "dream","erase","dreamer","eraser" };
int Len[] = {5,5,7,6};

int main(void)
{
	int len;
	int i;

	scanf("%s",S);
	len = strlen(S);

	while (len > 0) {
		for (i = 0; i < 4; i++) {
			if (len >= Len[i] && strcmp(tbl[i], &S[len - Len[i]]) == 0) {
				S[len - Len[i]] = '\0';
				break;
			}
		}
		if (i == 4) {
			printf("NO\n");
			return 0;
		}
		len -= Len[i];
	}
	printf("YES\n");
	return 0;
}
