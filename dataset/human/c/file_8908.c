#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, H, W;
	char s[52][52] = {};
	scanf("%d %d", &H, &W);
	for (i = 1; i <= H; i++) scanf("%s", &(s[i][1]));
	
	int flag = 1;
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W; j++) {
			if (s[i][j] == '#' && s[i-1][j] != '#' && s[i+1][j] != '#' && s[i][j-1] != '#' && s[i][j+1] != '#') flag = 0;
		}
	}
	
	if (flag == 1) printf("Yes\n");
	else printf("No\n");
	fflush(stdout);
	return 0;
}
