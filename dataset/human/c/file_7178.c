#include <stdio.h>

int main(){
	int H, W, i, j;
	while (1){
		scanf("%d%d", &H, &W);
		if(!H && !W) return 0;
		for (i = 1;i <= H;i++){
			for (j = 1;j <= W;j++){
				if (j % 2 == i % 2) putchar('#');
				else putchar('.');
			}
			puts("");
		}
		puts("");
	}
}
