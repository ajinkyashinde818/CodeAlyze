#include<stdio.h>

int main(){
	int size=0;
	int min=0,max=0;
	int array[200000]={};
	scanf("%d",&size);
	scanf("%d",&min);
	for(int i=1; i<size; i++){
		scanf("%d",&array[i]);
		if(i==1){
			max=array[i]-min;
		}else if(array[i]-min>max){
			max=array[i]-min;
		}
		if(min>array[i]){
			min=array[i];
		}
	}
	printf("%d\n",max);
	return 0;
}
