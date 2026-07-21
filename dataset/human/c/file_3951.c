#include <stdio.h>

int main() {
	int A,B,K;
	scanf("%d %d %d",&A,&B,&K);
	int large=(A > B) ? A : B;
	int Common_div[large];
	int cnt=0;
	for (int i = 1; i <= large; i++) {
		if (A%i == 0 && B%i == 0) {
			Common_div[cnt] = i;
			cnt++;
		}
	}
	printf("%d\n",Common_div[cnt-1-(K-1)]);
	return 0;
}
