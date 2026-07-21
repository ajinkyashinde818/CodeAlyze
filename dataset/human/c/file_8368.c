#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main(void){
	int a,b,c;
	int i,j,k;
	int m,n;
	char str[100];
	char d;
	scanf("%d",&a);
	scanf("%s",str);
	scanf("%d",&b);

	d = str[b-1];
	for(i=0;i<a;i++){
		if(str[i]!=d){
			printf("*");
		}else{
			printf("%c",d);
		}
	}
	printf("\n");

	return 0;
}
