#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	int N,M;
	scanf("%d %d",&N,&M);

	char A[50][50];
	char B[50][50];
	char input_A[50];
	char input_B[50];

	for(int i = 0; i < N; i++){
		scanf("%s",input_A);
		for(int j = 0; j < N; j++){
			if(input_A[j] == '#'){
				A[i][j] =  '#';
			}
			else{
				A[i][j] = '.';
			}
		}
	}
	for(int i = 0; i < M; i++){
		scanf("%s",input_B);
		for(int j = 0; j < M; j++){
			if(input_B[j] == '#'){
				B[i][j] =  '#';
			}
			else{
				B[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < N; i++){
		// printf("A[%d] = %s\n",i,A[i]);
	}
	for (int i = 0; i < M; i++){
		// printf("B[%d] = %s\n",i,B[i]);
	}

	int k = 0;
	char *s;
	int place;

	for (int i = 0; i < N; i++){
		s = strstr(A[i],B[k]);
		place = s -A[i];

		/*printf("%d times s = %s\n",i,s);
		printf("place = %d\n",place);
		printf("A[%d] = %s\n",i,A[i]);
		printf("B[%d] = %s\n",k,B[k]);*/
		if(s != NULL){
			k++;
		}
		else{
			k = 0;
		}
		if(k == M){
			printf("Yes\n");
			return 0;
		}
	}

	printf("No\n");

	return 0;
}
