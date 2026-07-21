#include<stdio.h>
#include<string.h>
int main()
{
  char inp[4];
  scanf("%s",inp);
  int i,j;
  char tmp;
  for(i=0;i<2;i++)
  {
    for(j=i+1;j<3;j++)
      if(inp[i]>inp[j])
      {
        tmp=inp[j];
        inp[j]=inp[i];
        inp[i]=tmp;
      }
  }
  if(strcmp(inp,"abc")==0)
    printf("Yes");
  else
    printf("No");
  return 0;
}
