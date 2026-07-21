#include <stdio.h>

int x,y,n;
int gcd(int a,int b){
	return b == 0 ?a :gcd(b,a%b);
}

void max(int a,int b){
	if(a < b){
		int t = a;
		a = b;
		b = t;
	}
}

int main()
{
	scanf("%d %d %d",&x,&y,&n);
	max(x,y);
	int i = gcd(x,y);
	for(;n > 0 && i >= 1;i--){
		if(x % i == 0 && y % i == 0) n--;
	}
	printf("%d",i + 1);
	return 0;
}
