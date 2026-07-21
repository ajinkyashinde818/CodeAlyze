#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int hight[n];
	int count=0;
	for(int i=0; i<n; i++){
		scanf("%d", &hight[i]);
		if(hight[i]>=k) count++;
	}
	
	printf("%d", count);
	
	
	return 0;
}
