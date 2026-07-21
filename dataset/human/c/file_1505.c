#include <stdio.h>

int main(){
	char num[] = "ABCDEF";

	char aa;
	char bb;
	scanf("%c %c",&aa,&bb);

	int a = 0;
	int b = 0;
	for(int i = 0; i < 6; i++){
		if(aa == num[i]){
			a = i;
		}
		if(bb == num[i]){
			b = i;
		}
	}
	if(a > b){
		printf(">\n");
	}else if(a == b){
		printf("=\n");
	}else{
		printf("<\n");
	}


	return 0;
}
