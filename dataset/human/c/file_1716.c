#include<stdio.h>

int n, i;
int a[20], c[20];
int b, s;
int main(void){
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", a+i);
	}
	for(i=0; i<n; i++){
		scanf("%d", &b);
		s+=b;
	}
	for(i=0; i<n-1; i++){
		scanf("%d", c+i);
	}
	for(i=0; i<n-1; i++){
		if(a[i]+1==a[i+1]){
			s+=c[a[i]-1];
		}
	}
	printf("%d\n", s);
}
