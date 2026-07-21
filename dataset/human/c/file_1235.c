#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare_string1(const void *a, const void *b) {
  return *(char *)a-*(char *)b;
}

int compare_string2(const void *a, const void *b) {
  return *(char *)b-*(char *)a;
}

int main(){
	
	char s[110],t[110];
	
	scanf("%s",s);
	scanf("%s",t);
	
	qsort(s,strlen(s),sizeof(char),compare_string1);
	qsort(t,strlen(t),sizeof(char),compare_string2);
	
	if(strcmp(s,t)<0){
		printf("\nYes\n\n");
	}else {
		printf("\nNo\n\n");
	}
	
	
	
	return 0;
}
