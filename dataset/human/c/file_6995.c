#include <stdio.h>

int main(void)
{
	int n;
	int w, h;
	
	while (scanf("%d %d", &h, &w)){
		if (w == 0 && h == 0){
			break;
		}
		n = 0;
		while (1){
			if (h != 0){
				while (1){
					if (n != w){
						printf("#");
						n++;
					}
					else {
						printf("\n");
						break;
					}
					if (n != w){
						printf(".");
						n++;
					}
					else {
						printf("\n");
						break;
					}
				
				}
				h--;
				n = 0;
			}
			else {
				printf("\n");
				break;
			}
			if (h != 0){
				while (1){
					if (n != w){
						printf(".");
						n++;
					}
					else {
						printf("\n");
						break;
					}
					if (n != w){
						printf("#");
						n++;
					}
					else {
						printf("\n");
						break;
					}
				
				}
				h--;
				n = 0;
			}
			else {
				printf("\n");
				break;
			}
		}
	}
	return (0);
}
