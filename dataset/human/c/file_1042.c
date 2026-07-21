#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main(){
	
	char str[100];
	int len,i;
	
	scanf("%s",&str);
	
	len=strlen(str);
	
	for(i=0;i<=len-9;i++){
		printf("%c",str[i]);
	}
	
	printf("\n");
	
	return 0;
}
