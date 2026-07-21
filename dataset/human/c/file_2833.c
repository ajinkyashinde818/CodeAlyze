#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	int K,S;
	int X,Y,Z;
	int XY;
	int count = 0;;

	scanf("%d %d",&K,&S);

	for(int i = 0; i <= K; i++){
		Z = i;
		XY = S - Z;
		for(int j = 0; j <= K; j++){
			Y = j;
			X = XY - Y;
			if(X <= K && X >= 0){
				count++;
				// printf("X=%d,Y=%d,Z=%d\n",X,Y,Z);
			}
			else{
				// printf("X=%d,Y=%d,Z=%d\n",X,Y,Z);
			}
			
		}
	}	
	printf("%d",count);
	return 0;
}
