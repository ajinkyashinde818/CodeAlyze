#include <stdio.h>

int max_v(int a,int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int min_v(int a,int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int main()
{
	int n;
	scanf("%d",&n);

	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	int ans = 0;
	
	int min = arr[0];
	int max = -1000000000;
	for(int i=1;i<n;i++){
		max = max_v(max,arr[i] - min);
		min = min_v(min,arr[i]);
	}

	printf("%d\n",max);

	return 0;
}
