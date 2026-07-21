#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int cmpf1(const void * v1, const void * v2)
{
  return (int)(*((unsigned char *)v1)) - (int)(*((unsigned char *)v2));
}
int cmpf2(const void * v1, const void * v2)
{
  return (int)(*((unsigned char *)v2)) - (int)(*((unsigned char *)v1));
}



int main()
{
  char s1[1024];
  char s2[1024];
  scanf("%s",s1);
  scanf("%s",s2);
  int l1,l2;
  l1 = strlen(s1);
  l2 = strlen(s2);
  (void)qsort((void*)s1,l1,1,cmpf1);
  (void)qsort((void*)s2,l2,1,cmpf2);
  if(!strcmp(s1,s2)){
    printf("No\n");
    return EXIT_SUCCESS;
  }
  if(strcmp(s1,s2)<0){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  
  return EXIT_SUCCESS;
}
