#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b);

int main()
{
	int i, a, b, k, g, cnt = 0;
	
	scanf("%d %d %d", &a, &b, &k);
	
	g = gcd(a, b);
	
	for(i = g; i > 0; i--){
		if(g % i == 0)
			cnt++;
		if(cnt == k){
			printf("%d", i);
			break;
		}
	}

	return 0;
}

int gcd(int a, int b){
	
	int tmp, r;
	
	if(a < b){
		tmp = a;
		a = b;
		b = tmp;
	}
	
	r = a % b;
	while(r!=0){
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}
