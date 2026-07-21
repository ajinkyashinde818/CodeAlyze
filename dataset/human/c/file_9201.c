#include <stdio.h>
#include <stdlib.h>

int main(void){
  int limits=0;
  int people=0;
  scanf("%d %d",&people,&limits);
  int * height=(int *)malloc(people*sizeof(int));
  for(int i=0;i<people;i++)
	  scanf("%d",&height[i]);
  int ret_val=0;
  for(int i=0;i<people;i++)
	  if(height[i]>=limits)
		  ret_val++;
  printf("%d",ret_val);
  return 0;
}
