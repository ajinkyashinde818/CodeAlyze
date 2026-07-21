#include <stdio.h>
int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int eq, eq2;
	int agrsim;
	if(a >= 10){
		printf("%d\n", b);
	} else{
		eq=100*(10-a);
		eq2= eq+b;
		printf("%d\n", eq2);
	}
	
	
	return 0;
}
