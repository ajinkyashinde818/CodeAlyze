#include<stdio.h>
int main(void)
{
  char str[3];
  scanf("%s",str);
  int i,cnta=0,cntb=0,cntc=0;
  for(i=0; i<3; i++)
  {
    if(str[i]=='a') cnta=1;
    else if (str[i]=='b') cntb=1;
    else cntc=1;
  }
  if(cnta==1 && cntb==1 && cntc==1) printf("Yes");
  else printf("No");
  return 0;
}
