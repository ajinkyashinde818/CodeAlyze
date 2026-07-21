#include<stdio.h>
#include<string.h>

int cmp1(const char *a,const char *b){
  return *a-*b;
}
int cmp2(const char *a,const char *b){
  return *b-*a;
}
int main(){
  char a[111],b[111];
  scanf("%s%s",a,b);
  qsort(a,strlen(a),sizeof(a[0]),cmp1);
  qsort(b,strlen(b),sizeof(b[0]),cmp2);
  puts(strcmp(a,b)<0?"Yes":"No");
}
