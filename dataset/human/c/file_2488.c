#include <stdio.h>
/*
date:20180407
name:A - abc of ABC
written by youkan_koshian_gurentai
*/

int main(void){
    char S[3];
	scanf("%s", S);
	int temp =0;
	for(int i=0; i<3;i++) {
		if(S[i]=='a') temp+=100;
		if(S[i]=='b') temp+=10;
		if(S[i]=='a') temp+=1;
	}
	if (temp == 111) printf("Yes");
	else puts("No");
    return(0);
}
