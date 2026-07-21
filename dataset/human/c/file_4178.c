#include <stdio.h>



int gcd(int a, int b) {
	if (b==0) return a;
	else return gcd(b,a%b);
}
/*
int factorization(int num, int prime) {
	int a;
	while ((num%prime)==0) {
		num /= prime;
		a++;
	}
}
*/
int main(void) {
	int a,b,k,g,ans;
	int prime[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	int factor[15];
	scanf("%d %d %d",&a,&b,&k);
	if (a<b) {
		g = a;
		a = b;
		b = g;
	}
	g = gcd(a,b);
//	printf("gcd= %d ",g);
	ans = g;
	while (k) {
		if ((g%ans)==0) k--;
		ans--;
	}
	printf("%d\n",ans+1);
	return 0;
}
