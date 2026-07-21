#include<stdio.h>
#include <string.h>
int main(void)
{
  char s[4];
  char x[4]="abc";
  scanf("%s",s);
  int n,m;
  
  
  for(n=0;n<3;n++)
  {
    for(m=0;m<3;m++)
    {
      if(s[m]==x[n])
        x[n]='o';
    }
        
  }
  if(strcmp(x,"ooo")==0)
    printf("Yes");
  else printf("No");
    
  
  return 0;
}
