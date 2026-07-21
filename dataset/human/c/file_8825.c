#include <stdio.h>
int main() {
	int h,w;
	scanf("%d %d",&h,&w);
	char square[h][w];
	for(int count = 0;count < h;count++) scanf("%s",square[count]);
	for(int counth = 0;counth < h;counth++) for(int countw = 0;countw < w;countw++) {
		if(square[counth][countw] == '#') {
			int check[4] = {0,0,0,0};
			if(counth != 0) if(square[counth - 1][countw] == '.') check[0] =1;
			if(counth != h - 1) if(square[counth + 1][countw] == '.') check[1] =1;
			if(countw != 0) if(square[counth][countw - 1] == '.') check[2] =1;
			if(countw != w - 1) if(square[counth][countw + 1] == '.') check[3] =1;
			if(check[0] && check[1] && check[2] && check[3]) {
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}
