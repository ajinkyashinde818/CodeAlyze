#include <stdio.h>

int main(void){
	char mozi[4];
	int i;
	
	for(i=0;i<3;i++){
		scanf("%c",&mozi[i]);
	}
	if(mozi[0]==mozi[1] || mozi[0]==mozi[2] || mozi[2]==mozi[1]){
		printf("No");
	}else{
		printf("Yes");
	}
	
	return 0;}
