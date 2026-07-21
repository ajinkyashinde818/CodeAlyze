#include <stdio.h>
#include <string.h>
int main (void)
{
  char str[50],name[50],set[9],fes[9]="FESTIVAL";
  int i,j;
  scanf("%s",str);
  for(i=0;i<50;i++)
  {
    for(j=0;j<9;j++)
    {
      set[j]=str[i+j];
    }
    if(strcmp(fes,set)==0)
    {
      for(j=0;j<i;j++)
      {
        name[j]=str[j];
      }
        name[i]='\0';
      break;
    }
  }
  printf("%s",name);
    putchar('\n');
  return 0;
}
