#include <stdio.h>
int main(void)
{
  char x,y;
  scanf("%c",&x);
  scanf("%c",&y);
  while(y==' ' || y=='\n')
  {
    scanf("%c",&y);
  }
  if(x<y)
  {
    printf("<\n");
  }
  else if(x>y)
  {
    printf(">\n");
  }
  else
  {
    printf("=\n");
  }
  return 0;
}
