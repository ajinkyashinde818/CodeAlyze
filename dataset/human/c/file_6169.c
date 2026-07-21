#include<stdio.h>
#define N 200000

int main(){
	int num,FX[N],max=-1000000000,sa,i,j;
	int min=0;

	scanf("%d",&num);

	for(i=0;i<num;i++){
		scanf("%d",&FX[i]);
	}

	min=FX[0];

	for(i=1;i<num;i++){
		sa=FX[i]-min;
		if(max<sa)
			max=sa;
		if(FX[i]<min)
			min=FX[i];
	}

	printf("%d\n",max);

	return 0;
}
