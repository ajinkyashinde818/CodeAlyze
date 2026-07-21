#include <stdio.h>
#include <string.h>

int main(void){
	char s[100001];
	char x;
	int count = 0, l = 0, r;

	scanf("%s", s);
	r = strlen(s) - 1;

	while(l < r){
		if(s[r] == s[l]) {
			l++;
			r--;
		}
		else if(s[l] == 'x'){
			count++;
			l++;
		}
		else if(s[r] == 'x'){
			count++;
			r--;
		}
		else {
			printf("-1\n");
			return 0;
	}
	}

printf("%d\n", count);

return 0;
	}
