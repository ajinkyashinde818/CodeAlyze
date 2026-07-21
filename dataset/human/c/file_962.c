#include<stdio.h>
int main(void)
{
    int e,y;
	scanf("%d",&e);
	scanf("%d",&y);
	if(e==0 && y<=1911){
	  printf("M%d\n",y-1867);
	 }
	else if(e==0 && y<=1925){
	  printf("T%d\n",y-1911);
	 }
	else if(e==0 && y<=1988){
	  printf("S%d\n",y-1925);
	 }
	else if(e==0 && y<=2016){
	  printf("H%d\n",y-1988);
	 }
	if(e==1 && y<=44){
	  printf("%d\n",y+1867);
	 }
	if(e==2 && y<=14){
	  printf("%d\n",y+1911);
	 }
	if(e==3 && y<=63){
	  printf("%d\n",y+1925);
	 }
	if(e==4 && y<=28){
	  printf("%d\n",y+1988);
	 }
	return 0;
}
