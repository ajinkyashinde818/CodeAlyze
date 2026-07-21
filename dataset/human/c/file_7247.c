#include <stdio.h>

int main(void)
{
	int i, j, H, W;

	while(1){
		scanf("%d %d", &H, &W);

		if((H == 0) && (W == 0)) break;

		for(j = 0;j < H;j++){
			for(i = 0;i < W;i++){
				if((i + j) % 2 == 0){
					printf("#");
				} else {
					printf(".");
				}
			}

			printf("\n");
		}
		printf("\n");

	}

	return 0;
}
