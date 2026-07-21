#include <stdio.h>
int main() 
{
    int h, w;
    char s[52][52] = {0};
	scanf("%d%d ", &h, &w);
	for (int i = 1; i <= h; i++) {
        scanf("%s", &s[i][1]);
    }
	for (int j = 1; j <= h; j++) {
        for (int i = 1; i <= w; i++) {
            if (s[j][i] == '#') {
                if (s[j - 1][i] == '#') continue;
                if (s[j + 1][i] == '#') continue;
                if (s[j][i - 1] == '#') continue;
                if (s[j][i + 1] == '#') continue;
                printf("No\n");
                return 0;
            }
        }
    }
	printf("Yes\n");
	return 0;
}
