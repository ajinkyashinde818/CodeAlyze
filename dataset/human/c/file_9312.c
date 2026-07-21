#include <stdio.h>
int main(void)
{
  int a,b,c;
  int i;
  int count;
  
  scanf("%d",&a);
  scanf("%d",&b);
  printf("\n");
  for(i=0;i<a;i++){
    scanf("%d",&c);
    if(c>=b){
      count+=1;
    }
  }
    printf("%d\n",count);
   
  return 0;
}
