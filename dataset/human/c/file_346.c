#include<stdio.h>
#include<string.h>
int main(){
	int N,R;
	scanf("%d %d", &N , &R );
	int rating;
	if (N<10){
		rating = R + 100 * (10-N);
	} else if (10<=N<=100 ){
		rating = R;
	}
	printf("%d",rating);
}
