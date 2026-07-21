#include <stdio.h>
int main(){
	int n[10000];
	int i=0;
	while(1){
		scanf("%d", &n[i]);
		if(!n[i]){
			break;
		}
		i++;
	}
	int limit=i;
	i=0;
	for(i=0;i<limit;i++){
		printf("Case %d: %d\n", i+1, n[i]);
	}
	
	return 0;
}
