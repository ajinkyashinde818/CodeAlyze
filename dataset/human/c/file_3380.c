#include <stdio.h>

int main(void){

  char s[100000+1];
	int end;
	for (int i = 0; i < 100000+1; i++) {
		scanf("%c", &s[i]);
		if (s[i] < 'a' || s[i] > 'z') {
			end = i-1;
			break;
		}
	}

	int flag = 1;
	for (int i = end; i >= 0; i--) {
		if (s[i] == 'm') {
			if (s[i-1] == 'a' && s[i-2] == 'e' && s[i-3] == 'r' && s[i-4] == 'd') {
				i = i-4;
			} else {
				flag = 0;
				break;
			}
		} else if (s[i] == 'r') {
			if (s[i-1] == 'e' && s[i-2] == 'm' && s[i-3] == 'a' && s[i-4] == 'e' && s[i-5] == 'r' && s[i-6] == 'd') {
				i = i-6;
			} else if (s[i-1] == 'e' && s[i-2] == 's' && s[i-3] == 'a' && s[i-4] == 'r' && s[i-5] == 'e') {
				i = i-5;
			} else {
				flag = 0;
				break;
			}
		} else if (s[i] == 'e') {
			if (s[i-1] == 's' && s[i-2] == 'a' && s[i-3] == 'r' && s[i-4] == 'e') {
				i = i-4;
			} else {
				flag = 0;
				break;
			}
		} else {
			flag = 0;
			break;
		}
	}

	if (flag == 1) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

  return 0;
}
