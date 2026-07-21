#include<stdio.h>

int input_num[9999], case_num = 0;
int i = 0;

int main() {
	do {
		scanf("%d", &input_num[case_num]);
		case_num++;
	} while (input_num[case_num-1] != 0);
	
	do {
		printf("Case %d: %d\n", i+1, input_num[i]);
		i++;
	} while (i != case_num-1);

	return 0;
}
