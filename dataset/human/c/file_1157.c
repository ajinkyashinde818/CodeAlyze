#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int func(const void *a,const void *b){
	if(*((char *)a) > *((char *)b)){
		return -1;
	}else if(*((char *)a) == (*(char *)b)){
		return 0;
	}else{
		return 1;
	}
}

int func2(const void *a,const void *b){
	if(*((char *)a) > *((char *)b)){
		return 1;
	}else if(*((char *)a) == (*(char *)b)){
		return 0;
	}else{
		return -1;
	}
}

int main(){
	int count=0;
	char S[101],T[101];
	scanf("%s",S);
	scanf("%s",T);
	int N=strlen(S);
	int M = strlen(T);
	qsort((void *)S,N,sizeof(char),func2);
	qsort((void *)T,M,sizeof(char),func);
	int check=strcmp(S,T);
	if(check<0){
		printf("Yes\n");
	}else{
		printf("No\n");
	}	
	return 0;
}
