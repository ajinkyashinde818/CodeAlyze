#include<stdio.h>
int main(){
	int Ac=0,Bc=0,Cc=0,i;
	char S[3];

	scanf("%s",S);

	for(i=0;i<3;i++){
		if(S[i] == 'a')	Ac++;
		if(S[i] == 'b')	Bc++;
		if(S[i] == 'c')	Cc++;
	}
	if(Ac==1 && Bc==1 && Cc==1){
		printf("Yes\n");
	}else{
		printf("No\n");
	}

}
