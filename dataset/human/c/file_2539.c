#include <stdio.h>

int main(void) {
	char s;
	int i, flag[3] = {0};
	
	for (i = 0; i < 3; i++) {
		scanf(" %c", &s);
		flag[s == 'a' ? 0 : s == 'b' ? 1 : 2] = 1;
	}
	
	if (flag[0] && flag[1] && flag[2])
		printf("Yes\n");
	else
		printf("No\n");
	
	return 0;
}
