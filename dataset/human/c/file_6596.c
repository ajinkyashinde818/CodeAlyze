#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int calc(int R[],int n){
	int ans=(R[1]-R[0]);
	int min=R[0];

	for(int i=1;i<n;i++){
		if(ans < (R[i]-min)){
			ans=(R[i]-min);
		}
		if(R[i] < min){
			min = R[i];
		}
	}

	return ans;
}

int main(){
    int n;
	int *R;

	scanf("%d",&n);
	R=(int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		scanf("%d",&R[i]);
	}

	int ans = calc(R,n);

	printf("%d\n",ans);
	
	return 0;
}
