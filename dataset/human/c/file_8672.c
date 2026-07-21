#include<stdio.h>

int main(){

	int N = 0;
	int count = 1;
	scanf("%d",&N);

	int a[N];
	for(int i=0; i<N; i++){
		scanf("%d",&a[i]);
	}

	for(int j=0; j<100002; j){
		if(a[j] == 2){
			printf("%d",count);		
			return 0;
		}else{
			j = a[j]-1;
			if(count > N){
				printf("-1");
				return 0;
			}
		}
		count ++;
	}

}
