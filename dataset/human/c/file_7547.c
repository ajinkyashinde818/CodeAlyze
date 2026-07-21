#include<stdio.h>
int main(){
	int a[150000];
	int i, j, size;
	for (i = 0; i < 150000; i++){
		scanf("%d", &a[i]);
		if (a[i] == 0){
			size = i;
			break;
		}
	}
	for (i = 0; i < size; i++)printf("Case %d: %d\n", i + 1, a[i]);
	return 0;
}
