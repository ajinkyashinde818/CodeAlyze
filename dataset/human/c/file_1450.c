#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){

	char line[256];

	fgets(line, sizeof(line), stdin);
	
	if(line[0] == '9' || line[1] == '9'){
		printf("Yes\n");
	}else{
		printf("No\n");
	}

	return 0;
}
