#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int strdcmp(const char *a, const char *b){
  return strcmp(b,a);
}
int main(){
  char s[101],t[101];
  scanf("%s %s",s,t);
  qsort(s,strlen(s),sizeof(char),strcmp);
  qsort(t,strlen(t),sizeof(char),strdcmp);
  puts(strcmp(s,t)<0?"Yes":"No");
  return 0;
}
