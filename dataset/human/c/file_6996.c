#include <stdio.h>

int main(void) {
	int H,W;
	int x,y;
	int index;
	char mozi[2]={'#','.'};
	scanf("%d %d",&H,&W);
	while(H!=0 || W!=0) {
		for(y=0;y<H;y++) {
			index=y%2;
			for(x=0;x<W;x++) {
				printf("%c",mozi[index]);
				index^=1;
			}
			printf("\n");
		}
		printf("\n");
		scanf("%d %d",&H,&W);
	}
	return 0;
}
