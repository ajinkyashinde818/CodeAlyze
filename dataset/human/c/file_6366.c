#include<stdio.h>

int main(){
    int n, max = 0, min = 0, i;
    
    scanf("%d", &n);
    
    int R[n];
    
    for(i = 0; i < n; i++){
    	scanf("%d", &R[i]);
    }
    
    min = R[0];
    max = R[1] - R[0];
    for(i = 1; i <= n - 1; i++){
    	if(R[i] - min > max){
    		max = R[i] - min;
    	}
    	if(R[i] < min){
    		min = R[i];
    	}
    	//printf("%d\n", R[i]);
    }
    
   	printf("%d\n", max);
   
    return 0;
}
