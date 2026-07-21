#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	int a,b;
	scanf("%d %d", &a, &b);
	if(a == b){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}
