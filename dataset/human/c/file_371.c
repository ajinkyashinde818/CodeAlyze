#include<stdio.h>
#include<stdlib.h>
#define BUFSIZE 10000
#include<math.h>
int N,R;

int main(void){
	scanf(" %d",&N);
	scanf(" %d",&R);
	if(N < 10){
		printf(" %d",R+100*(10-N));
	}else{
		printf(" %d",R);
	}
		
		
		
}
