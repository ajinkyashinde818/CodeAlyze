#include <stdio.h>
#include <stdlib.h>
int main(void){
	int n;
	long k;
	int *a;
	int *visited;
	int *x;
	scanf("%d", &n);
	scanf("%ld", &k);
	a = (int *)malloc(sizeof(int) * n);
	visited = (int *)malloc(sizeof(int) * n);
	x = (int *)malloc(sizeof(int) * n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		visited[i] = 0;
		x[i] = 0;
	}
	int tmp_city = 1;
	int j = 0;
	while(visited[tmp_city-1] == 0){
		visited[tmp_city-1] = 1;
		x[j] = tmp_city;
		j++;
		tmp_city = a[tmp_city-1];
	}
	
	int l = 0;
	while(x[l] != tmp_city){
		l++;
	}

	if(k >= l){
		k = (k-l)%(j-l);
		printf("%d\n", x[l+k]);
	}
	else{
		printf("%d\n", x[k]);
	}
	return 0;
}
