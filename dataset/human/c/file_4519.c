#include <stdio.h>
int main(void){
	int n;
	int d1;
	int d2;
	int zoro_count = 0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &d1);
		scanf("%d", &d2);
		if(zoro_count < 3){
			if(d1 == d2){
				zoro_count++;
			} else {
				zoro_count = 0;
			}
		}
	}
	if(zoro_count == 3){
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
