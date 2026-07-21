#include<stdio.h>
#define rep(i,n) for(i=0; i<n; i++)

int main(void){
	int n, r, m;
	scanf("%d%d", &n, &r);
	m=r+100*(10-n);
	if(n >= 10){
		printf("%d\n", r);
	}else{
		printf("%d", m);
	}
	return 0;
}
