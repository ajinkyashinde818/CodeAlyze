#include <stdio.h>

main(){
	char str1,str2;
	int x,y;
	scanf("%c",&str1);
	scanf("%c",&str2);
	scanf("%c",&str2);
	x=(int)str1;
	y=(int)str2;
	 
	if(x>y){
		printf(">\n");
	}
	if(x<y){
		printf("<\n");
	}
	if(x==y){
		printf("=\n");
	}
	return 0;
}
