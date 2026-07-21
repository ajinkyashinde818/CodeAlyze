#include<stdio.h>
int main(){
	int n,temp;
    scanf("%d",&n);
    
    int a[n-1];
    int i=0;
    int count = 0;

    for(int k=0;k<n;k++){
   	    scanf("%d",&temp);
    	a[k] = temp;
    }
    
    
    while(a[i] != 2 && count < n){
    	i = a[i]-1;
    	count = count+1;
    }
	if(a[i] == 2){
		count = count+1;
		printf("%d",count);
		printf("\n");
	}else{
		printf("-1");
		printf("\n");
	}

}
