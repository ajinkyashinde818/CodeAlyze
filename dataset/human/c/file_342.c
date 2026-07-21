#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(void){
	int N,R;
	scanf("%d %d",&N,&R);
	if(N<10){
		printf("%d",R+100*(10-N));
	}else{
		printf("%d",R);
	}

}
