#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int n,d,x;
int a[100];

int main(void){
	scanf("%d", &n);
	scanf("%d %d", &d, &x);
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
		x += (d-1)/a[i];
		x++;
	}
	printf("%d", x);
	
}
