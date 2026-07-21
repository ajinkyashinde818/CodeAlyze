#include<stdio.h>

int main (void){
	int N;
	int i,j;
	scanf("%d",&N);
	int dish[20];
	int points[20];
	int add[20];
	for (i=0;i<N;i++){
		scanf("%d",&dish[i]);
	}
	for (i=0;i<N;i++){
		scanf("%d",&points[i]);
	}
	for (i=0;i<N;i++){
		scanf("%d",&add[i]);
	}
	int sum=0;
	for (i=0;i<N;i++){
		sum+=points[dish[i]-1];
		if ((i+1)<N && ((dish[i]==(dish[i+1])-1)))
		sum+=add[dish[i]-1];
	}
	printf("%d\n",sum);
	return 0;
}
