#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589793

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int broken[m+5];
	for(int i=0; i<m; i++){
		scanf("%d", &broken[i]);
	}
	
	int i=3, j=0;
	unsigned long int temp, way1, way2;
	if(broken[0] == 1){
		if(broken[1] == 2){
			way1 = 0;
			i = n+1;
			j = 2;
		}
		else{
			way1 = 1;
			way2 = 0;
			j = 1;
			if(n==1) way1 = 0;
		}
	}
	else{
		if(broken[0] == 2){
			way1 = 0;
			way2 = 1;
			j = 1;
			if(n==1) way1 = 1;
		}
		else{
			way1 = 2;
			way2 = 1;
			if(n==1) way1 = 1;
		}
	}
	while(i<=n){
		if(i == broken[j]){
			temp = 0;
			j++;
			//printf("Yes");
		}
		else{
			temp = way1+way2;
		}
		way2 = way1;
		way1 = temp;
		//printf("%d段目:%lu\n", i, temp);
		temp = temp%1000000007;
		way1 = way1%1000000007;
		way2 = way2%1000000007;
		i++;
	}
	
	way1 = way1%1000000007;
	printf("%lu", way1);
	
	
	return 0;
}
