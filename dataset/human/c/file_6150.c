#include <stdio.h>
int main(){
    int n;
	scanf("%d",&n);
	int i;
	int num;
	int min = 2147483640;
	int maxValue = -2147483640;
	for(i=0;i<n;i++){
		scanf("%d",&num);
		if(num - min > maxValue){
			maxValue = num-min;
		}
		if(num < min){
			min = num;
		}
	} 
	printf("%d\n",maxValue);
}
