#include <stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	int data;
	scanf("%d",&data);
	int max=-1000000000;
	int min=data;
	int i;
	for(i=1;i<N;i++){
		scanf("%d",&data);
		max=max>data-min?max:data-min;
		min=min<data?min:data;
	}
	printf("%d\n",max);
	return 0;
}
