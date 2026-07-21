#include <stdio.h>

int main(void) {
	int e,y;
	
	scanf("%d%d",&e,&y);
	if(e==0){
		if(1868<=y && y<=1911) printf("M%d\n",y-1868+1);
		else if(y<=1925) printf("T%d\n",y-1912+1);
		else if(y<=1988) printf("S%d\n",y-1926+1);
		else printf("H%d\n",y-1989+1);
		
	} else if(e==1){
		printf("%d\n",1868+y-1);
	} else if(e==2){
		printf("%d\n",1912+y-1);
	} else if(e==3){
		printf("%d\n",1926+y-1);
	} else{
		printf("%d\n",1989+y-1);
	}
	
	return 0;
}
