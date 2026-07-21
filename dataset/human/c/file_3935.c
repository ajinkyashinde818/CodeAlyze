#include<stdio.h>


 
int main() {

	int i,cnt=0,a, b,c;

	scanf("%d%d%d", &a, &b,&c);

	for (i = 100; i > 0; i--) {
		if (a%i == 0 && b%i == 0) cnt++;
		if (cnt == c)break;
		

	}
	printf("%d", i);


	return 0;
}
