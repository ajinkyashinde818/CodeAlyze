#include <stdio.h>
int main(){
	int A, B;
	long long int m, n;
	double d;
	scanf("%d %d", &A, &B);
	if (A>B){
		n=1;
		while (1){
			m=A*n++;
			d=(double)m/B;
			if (d==(int)d){
				printf("%lld\n", m);
				return 0;
			}
		}
	}
	else{
		n=1;
		while (1){
			m=B*n++;
			d=(double)m/A;
			if (d==(int)d){
				printf("%lld\n", m);
				return 0;
			}
		}
	}
}
