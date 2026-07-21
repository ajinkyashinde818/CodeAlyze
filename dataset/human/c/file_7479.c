#include <stdio.h>
int main(){
	int i = 0;
	int x[10000];

	scanf("%d",&x[0]);
	while(x[i] != 0){
		i++;
		scanf("%d",&x[i]);
	}

	i = 0;

	while(x[i] != 0){
		printf("Case %d: %d\n", i + 1, x[i]);
		i++;
	}

	return 0;
}
