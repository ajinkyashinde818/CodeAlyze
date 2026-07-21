#include <stdio.h>
#include <math.h>

int min(int a, int b) {
	if(a > b) return b;
	return a;
}

int max(int a, int b) {
	if(a > b) return a;
	return b;
}

int main() {
	char s[3];
	scanf("%s", s);
	int array[3] = {0, 0, 0};
	int i = 0;
	for(i = 0; i < 3; i++) {
		if(s[i] == 'a') array[0]++;
		else if(s[i] == 'b') array[1]++;
		else if(s[i] == 'c') array[2]++;
	}

	for(i = 0; i < 3; i++) {
		if(array[i] != 1) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	//char buffer[128];
	//scanf("%s", buffer);
	return 0;
}
