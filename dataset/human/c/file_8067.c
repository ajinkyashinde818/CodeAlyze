#include <stdio.h>

long long int gcd(long long a,long long b){
	long long int tmp;
	if(a<b){
		tmp=a;
		a=b;
		b=tmp;
	}
	if(b==0)return a;
	return gcd(b,a%b);
}

main(){

	int T;
	long long int a,b,c,d;/*
	scanf("%lld %lld",&a,&b);
	printf("%lld\n",gcd(a,b));
	return 0;*/
	long long m;
	scanf("%d",&T);
	while(T-->0){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		if(a<b || d < b){
			puts("No");
			continue;
		}
		a%=b;
		d%=b;
		if(c>b || (a<=c&&d==0)){
			puts("Yes");
			continue;
		}else if(d==0){
			puts("No");
			continue;
		}
//		puts("muzu");
		// b > c
		m=gcd(b,d);
		a+=(c-a)/m*m;
		if(a+m>=b)
			puts("Yes");
		else
			puts("No");
	}
}
