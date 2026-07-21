#include <stdio.h>

int main(void) {
	int x, y,i, c, cou;
	while(scanf("%d%d", &y, &x)){
		if(!x && !y) break;
		for(i = 0; y > i; i++){
		cou = 0;
			for(c = 0; x > c; c++){
				cou++;
				printf((cou+i) % 2 ? "#" : ".");
			}
			printf("\n");
		}
			printf("\n");
	}
	return 0;
}
