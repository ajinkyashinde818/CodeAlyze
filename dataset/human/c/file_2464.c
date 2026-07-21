#include <stdio.h>

char S[5];

int check[5];

int main() {

	scanf("%s",S);

	int i;

	for(i=0;i<3;i++){
	check[S[i]-'a']++;
	}

	if(check[0]==1&&check[1]==1&&check[2]==1){
	printf("Yes\n");
	}
	else{
	printf("No\n");
	}

	return 0;
}
