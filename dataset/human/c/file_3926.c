#include<stdio.h>
#include<stdlib.h>

int main(void){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	
	int i;
	int count = 0;
	for(i = (a>b)?a:b;;i--){
		if(a%i==0&&b%i==0)count++;
		if(count == c){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
