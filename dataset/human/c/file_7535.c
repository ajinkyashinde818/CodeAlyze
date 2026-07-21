#include <stdio.h>

int main(void) {
	int arr[10000];
	int cnt = -1;
	do{
		cnt++;
		scanf("%d",&arr[cnt]);
	}while(arr[cnt] != 0);
	for(int i = 0; i < cnt; i++){
		printf("Case %d: %d\n",i+1,arr[i]);
	}
	return 0;
}
