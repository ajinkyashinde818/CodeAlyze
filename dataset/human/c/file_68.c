#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>




int main() {
	int a, b, c,n,cnt=0;
	
	scanf("%d%d%d%d", &a,&b,&c,&n);
	for (int i = 0; a*i <= n; i++) {
		for (int j = 0; j*b <= n; j++) {
			if ((n - a * i - j * b) % c ==0 && n-a*i-b*j>=0) {
				cnt++;
				//printf("%d%d\n", i, j);
			}
		}

	}
	printf("%d", cnt);
	




	return 0;
}
