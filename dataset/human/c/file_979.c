#include<stdio.h>
int main(void){
	int e,y;
	scanf("%d%d",&e,&y);
	if(e==1)
	printf("%d\n",y+1867);
	else if(e==2)
	printf("%d\n",y+1911);
	else if(e==3)
	printf("%d\n",y+1925);
	else if(e==4)
	printf("%d\n",y+1988);
	else{
	if(y>1988)
	printf("H%d\n",y-1988);	
	else if(y>1925)
	printf("S%d\n",y-1925);
	else if(y>1911)
	printf("T%d\n",y-1911);
	else
	printf("M%d\n",y-1867);
	}
	return 0;
}
