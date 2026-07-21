#include<stdio.h>
#include<string.h>

int main(){

	int N,M;
	int Flag=0;
	int start=50;
	char A[50][50];
	char B[50][50];

	scanf("%d %d",&N,&M);

	for(int i=0; i<N; i++){
		scanf("%s",A[i]);
	}

	for(int j=0; j<M; j++){
		scanf("%s",B[j]);
	}

	for(int i=0; i<N; i++){
			if( strstr(A[0],B[i]) != NULL){
				if(start > i){
					start = i;
				}
			}
	}

	for(int i=0; i<M; i++){
		if( strstr(A[i+start],B[i]) == NULL){
			Flag = 1;
		}else{
			
		}
	}

	if(Flag==0){
		printf("Yes");
	}else{
		printf("No");
	}

	return 0;


}
