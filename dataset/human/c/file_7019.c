#include <stdio.h>

int main(int argc, char const *argv[])
{
	int h, w;
	int i, j;

	while (scanf("%d %d", &h, &w), h){
		for (i = 0; i < h; i++){
			for (j = 0; j < w; j++){
				if ((i + j) % 2) printf(".");
				else printf("#");
			}
			puts("");
		}
		puts("");
	}
	return (0);
}
