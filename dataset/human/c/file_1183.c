#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int sort1(const void *a, const void *b){
  if(*(char *)a > *(char *)b){
    return -1;
  }else if(*(char *)a == *(char *)b){
    return 0;
  }
  return 1;
}

int sort2(const void *a, const void *b){
  if(*(char *)a < *(char *)b){
    return -1;
  }else if(*(char *)a == *(char *)b){
    return 0;
  }
  return 1;
}

int main(void){
  char s[101], t[101];
  int l, f=0, i;
  scanf("%s",s);
  scanf("%s",t);
  qsort((void *)s, strlen(s), sizeof(s[0]), sort2);
  qsort((void *)t, strlen(t), sizeof(t[0]), sort1);
  l = strlen(s);
  if(l>strlen(t)) l=strlen(t);
  for(i=0;i<l;i++){
    if(s[i]>t[i]){f=1; break;}
    else if(s[i]<t[i]){f=2; break;}
  } 
  if((f==0 && strlen(s)<strlen(t)) || f==2) printf("Yes\n");
  else printf("No\n");
  return 0;
}
