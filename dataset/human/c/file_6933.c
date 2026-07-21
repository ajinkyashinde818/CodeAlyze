#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
	int n, m;
	scanf("%d%d",&n ,&m);
	if(n==m){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
    return 0; 
}
