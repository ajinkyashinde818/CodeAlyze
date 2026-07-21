#include<stdio.h>

int main(){
	int i;
	int data[10000];
	for(i = 0;i < 10000;i++){
		scanf("%d", &data[i]);
		if(data[i] != 0){
			printf("Case %d: %d\n", i + 1, data[i]);
		}else {
			break;
		}
	}
	return 0;
}
