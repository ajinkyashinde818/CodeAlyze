#include <stdio.h>
int main()
{
	int h, w, i, j;
	while("無限ループこわい"){
		scanf("%d %d", &h, &w);
		if(h == 0 && w == 0) break;
		for(i = 0; i < h; i++){
			if(i%2 == 0){
				for(j = 0; j < w; j++){
					if(j%2 == 0) printf("#");
					else printf(".");
				}
			}else{
				for(j = 0; j < w; j++){
					if(j%2 == 1) printf("#");
					else printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
    	return 0;
}
