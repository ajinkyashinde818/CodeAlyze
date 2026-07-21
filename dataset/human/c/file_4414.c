#include <stdio.h>

int main(void) {
	int N, DB, DA;
	int judge = 0;
	//Db Dbefor Da Dafter
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &DA, &DB);
		if (judge!=3) {
			if (DA == DB)
				judge++;
			else
				judge = 0;
		}
	}
	if (judge == 3)
		printf("Yes");
	else
		printf("No");
	return 0;
}
