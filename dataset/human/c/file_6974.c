#include <stdio.h>

int main(){
	int H, W, i, j;
	while (scanf("%d %d",&H,&W)){
		if (H == 0|W == 0){ break; }
		for (i = 0; i < H; i++){
			for (j = 0; j < W; j++){
				if (i % 2 == 1){
					if (j % 2 == 1){
						printf("#");
					}
					else{ printf("."); }
				}else{
					if (j % 2 == 0){
						printf("#");
					}
					else{ printf("."); }
				}
			}
			printf("\n");
		}printf("\n");
	}

	return 0;
}
