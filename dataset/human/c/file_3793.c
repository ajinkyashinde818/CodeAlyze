#include<stdio.h>
#include<string.h>

int main() {
	
	long A;
	long B;
	long C;
	long D;
	long i = 1;
	long ans = 0;
	
	scanf("%ld %ld", &A,&B);

	if (A >= B) {
		C = A;
		D = B;
	}
	else
	{
		C = B;
		D = A;
	}

	while (ans == 0)
	{
		if ((C * i) % D == 0) {
			ans = C * i;
		}
		else {
			i = i + 1;
		}
	}

	printf("%ld", ans);

	return 0;
}
