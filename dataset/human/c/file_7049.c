#include<stdio.h>

void put_even(int n){
	int i=1;
	for( ;i<=n; i++){
		if(i % 2) putchar('.');
		else  putchar('#');
	};
	putchar('\n');
}

void put_odd(int n){
	int i=1;
	for( ;i<=n; i++){
		if(i % 2) putchar('#');
		else  putchar('.');
	};
	putchar('\n');
}

int main(void){
	int i;
	int m,n;

	while(1){
	scanf("%d %d", &m, &n);
	if(m==0 && n==0) break;
	for(i=1; i<=m; i++){
		if(i % 2) put_odd(n);
		else put_even(n);
	};
	putchar('\n');
	};

	return (0);
}
