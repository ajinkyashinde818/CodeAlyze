#include<stdio.h>
int main() {
	int x[10000],i=0,tmp=0,flg=0;
	while (flg == 0) {
		scanf("%d", &x[i]);
		if (x[i] == 0) flg = 1;
		i++;
	}
	tmp = i-1;
	for (i = 0;i < tmp;i++) {
		printf("Case %d: %d\n", i + 1, x[i]);
	}
	return 0;
}
