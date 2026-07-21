#include <stdio.h>

int main(void)
{
	int h, w;

	while(1){
		bool flag_dot = false;
		scanf("%d %d", &h, &w);
		if(h == 0 && w == 0)
			break;
		
		for(int i = 0; i < h; i++){
			if(i % 2 == 0)
				flag_dot = false;
			else
				flag_dot = true;
				
			for(int j = 0; j < w; j++){
				if(flag_dot)
					printf(".");
				else
					printf("#");
				flag_dot = !flag_dot;
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;	
}
