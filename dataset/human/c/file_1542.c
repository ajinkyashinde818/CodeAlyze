#include<stdio.h>
#include<string.h>

int main(void)
{
  char x,y,dammy;
  scanf("%c%c%c",&x,&dammy,&y);
  if(x>y)
    printf(">\n");
  else if(x<y)
    printf("<\n");
  else
    printf("=\n");
  return 0;
}
