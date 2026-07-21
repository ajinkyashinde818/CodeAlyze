#include <stdio.h>
#include <string.h>

int main(void) {
	int x;
	char s[101];
	
	scanf("%d", &x);
	memset(s, 0, sizeof(s));
	
	if(x >= 0 && x < 1200){
		strcat(s, "ABC");
	}else if(x >= 1200){
		strcat(s, "ARC");
	}
	
	printf("%s\n", s);
	
	return 0;
}
