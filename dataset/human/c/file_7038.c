#include <stdio.h>

main()
{
	int h, w;
	scanf("%d %d", &h, &w);
	
	int i, j;
	while(h!=0||w!=0){
		for(i=0; i<h; i++){
				for(j=0; j<w; j++){
					if(i%2!=0){
						if(j%2!=0){
							printf("#");
						} else if(j%2==0){
							printf(".");
						}
					} else if(i%2==0){
						if(j%2!=0){
							printf(".");
						} else if(j%2==0){
							printf("#");
						}
					}
					if(j==w-1){
					printf("\n");
					}
					
				}
				
				
			}	
		printf("\n");
		scanf("%d %d", &h, &w);
		}

	return 0;
}
