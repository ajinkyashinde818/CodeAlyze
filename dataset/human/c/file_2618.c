#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	char S[4];
	scanf("%s", S);

	switch (S[0]) {
	case 'a':
		switch (S[1]) {
		
		case 'b':
			switch (S[2]) {
			case 'c':
				printf("Yes\n");
				break;

			default:
				printf("No\n");
			}
			break;

		case 'c':
			switch (S[2]) {
			case 'b':
				printf("Yes\n");
				break;

			default:
				printf("No\n");
				break;

			}
			break;

		default:
			printf("No\n");
		}

		break;

	case 'b':
		switch (S[1]) {

		case 'a':
			switch (S[2]) {
			case 'c':
				printf("Yes\n");
				break;

			default:
				printf("No\n");
			}
			break;

		case 'c':
			switch (S[2]) {
			case 'a':
				printf("Yes\n");
				break;

			default:
				printf("No\n");
				break;

			}
			break;

		default:
			printf("No\n");
		}
		break;

	case 'c':
		switch (S[1]) {

		case 'a':
			switch (S[2]) {
			case 'b':
				printf("Yes\n");
				break;

			default:
				printf("No\n");
			}
			break;

		case 'b':
			switch (S[2]) {
			case 'a':
				printf("Yes\n");
				break;

			default:
				printf("No\n");
				break;

			}
			break;

		default:
			printf("No\n");
		}

	}

	return 0;
}
