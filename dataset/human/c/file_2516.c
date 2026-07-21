#include<stdio.h>

int main(void) {
	char c[4];
	int i;
	int abc[3] = { 0,0,0 };
	scanf("%s", &c);

	for (i = 0; i < 3; i++) {
		if (c[i] == 'a') {
			abc[0] += 1;
		}
		else if(c[i] == 'b'){
			abc[1] += 1;
		}
		else {
			abc[2] += 1;
		}
	}

	if (abc[0] == 1 && abc[2] == 1 && abc[2] == 1) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	return 0;
}
