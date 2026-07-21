#include<stdio.h>
#include<limits.h>

int main(){
	int i, j, n, r, ans, min;
	min = INT_MAX;
	ans = INT_MIN;

	scanf("%d", &n);	
	
	for(i = 0; i<n; i++){
		scanf("%d", &r);
		if(r - min > ans) 
			ans = r - min;
		if(r < min)
			min = r;
	}


	printf("%d\n", ans);

	return 0;
}
