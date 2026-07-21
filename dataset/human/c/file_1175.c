#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp1(const void *a,const void *b)
{
  if(*(char*)a>*(char*)b)
  {
    return 1;
  }
  else if(*(char*)a<*(char*)b)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

int cmp2(const void *a,const void *b)
{
   if(*(char*)a<*(char*)b)
  {
    return 1;
  }
  else if(*(char*)a>*(char*)b)
  {
    return -1;
  }
  else
  {
    return 0;
  }
} 
int main()
{
  char s[100]={},t[100]={};
  
  scanf("%s%s",s,t);
  
  int ls=strlen(s),lt=strlen(t);
  int i;
  
  qsort(s,ls,sizeof(char),cmp1);
  qsort(t,lt,sizeof(char),cmp2);
  
  if(strcmp(s,t)<0)
  {
    printf("Yes\n");
  }
  else
  {
    printf("No\n");
  }
  
  return 0;
}
