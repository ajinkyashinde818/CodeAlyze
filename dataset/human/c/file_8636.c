#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	int N;

	int check = 1;
	int count = 0;
	scanf("%d",&N);
	int a[N];

	for(int i=1; i<N+1; i++){
		scanf("%d",&a[i]);
	}

	for(int i=0; i<N; i++){

	}

	while(check != 2){
		check = a[check];
		count ++;
		if(count > N){
			printf("%d",-1);
			return 0;
		}
	}

	printf("%d",count);
	return 0;
}
