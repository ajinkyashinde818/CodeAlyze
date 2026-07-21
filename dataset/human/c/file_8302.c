#include<stdio.h>

int main(){
  int a,c,i;
  char b[11],e;
  scanf("%d\n%s\n%d",&a,b,&c);
  e=b[c-1];
  for (i=1;i<=a;i++){
    if(b[i-1]!=e){
      b[i-1]='*';
    }
  }
  printf("%s",b);
  return 0;
}
