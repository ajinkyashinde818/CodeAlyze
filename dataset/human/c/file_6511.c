#include<stdio.h>

int main(){
	int num,i;
	int min,max=-2147483648;
	int input;
	
	scanf("%d",&num);
	
	
	scanf("%d",&input);
	min=input;
	
	for(i=1;i<num;i++){
		scanf("%d",&input);
		
		if(max<input-min){
			max = input-min;
		}
		
		if(input<min){
			min=input;
		}
	}
	
	printf("%d\n",max);
	
	return 0;
}
