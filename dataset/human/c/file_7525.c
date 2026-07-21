#include <stdio.h>

int main(){
	int i, a;
	i = 1;
	scanf("%d", &a);
	if(a != 0){
		printf("Case %d: %d\n", i, a);
		i = 2;
	while(a != 0){
		scanf("%d", &a);
		if(a == 0){
			break;
		}
		printf("Case %d: %d\n", i, a);
		i ++;
	}
	}
	return 0;
}
