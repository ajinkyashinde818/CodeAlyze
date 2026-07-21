#include <stdio.h>

int n;
int a[100000];

int main(){

	int i;

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	int search_num = a[0];
	int count = 0;
	while(count < n){
		count++;
		if(search_num == 2)
			break;
		search_num = a[search_num-1];
	}

	if(count >= n){
		printf("-1\n");
	} else {
		printf("%d\n",count);
	}
	return 0;
}
