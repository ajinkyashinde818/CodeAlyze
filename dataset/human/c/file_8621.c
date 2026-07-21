#include<stdio.h>
    
    int main(){
    	int n,i;
		int current = 1;
		int count = 0;
    	scanf("%d",&n);
        int a[n];

    	for(i = 0;i < n;i++){
    		scanf("%d",&a[i]);
		}

		while(current != 2){

			if(count > n){
	
				printf("-1");
				return 0 ;

			}
			current = a[current - 1];
			count ++;
		}


		printf("%d",count);

		return 0;

	}
