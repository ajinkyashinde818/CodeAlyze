#include <stdio.h>

int main(){
	int k, s;
	int total = 0;
	scanf("%i %i", &k, &s);
	for(int x=0; x <= k; x++){
		if (x>s){
			break;
		}
		for(int y=0; y <= k; y++){
			if ((x+y)>s){
				break;
			}
			if ((0<=(s-x-y))and((s-x-y)<=k)){
					total++;
			}
			
		}
	}
	printf("%i\n", total);
	return 0;
}
