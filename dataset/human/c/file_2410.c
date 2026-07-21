#include<stdio.h>

int main() {
	int i,counta=0,countb=0,countc=0;
	char a[4];

	scanf("%s", a);

	for (i = 0; i < 3; i++) {
		switch (a[i]) {
		case 'a':
			counta++;
			break;
		case 'b':
			countb++;
			break;
		case 'c':
			countc++;
			break;
		

		}
	}
	if (counta == 1 && countb == 1 && countc == 1)printf("Yes\n");
	else printf("No\n");
	return 0;
}
