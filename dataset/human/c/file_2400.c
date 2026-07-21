#include <stdio.h>
char S[5];
int A[3]={0};
int main(int argc, char *argv[]){
	int i;
	scanf("%s", S);
	for(i=0; i<3; i++){
		A[S[i]-'a']++;
	}
	if(A[0]==1 && A[1]==1 && A[2]==1) printf("Yes");
	else printf("No");
	return 0;
}
