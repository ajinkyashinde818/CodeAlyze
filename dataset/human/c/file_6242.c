#include <stdio.h>
#include <limits.h>
int main(void)
{
	int i,n;
	scanf("%d", &n);
	int a[n];
	
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	int max = INT_MIN;
	int min = a[0];
	
	for(int i=1; i <n; i++){
		if(max < a[i]-min){
			max = a[i]-min;
		}
		
		if(min > a[i]){
			min = a[i];
		}
	}
	
	printf("%d\n", max);
	
	return 0;
}
