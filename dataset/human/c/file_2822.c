#include<stdio.h>

int main(void){

  int k,s;
  int i=0;
  int a, b, c;

  scanf("%d %d",&k,&s);

  for(a=0;a<=k && a<=s;a++){
    for(b=0;b<=k && a+b<=s;b++){
      if(s-a-b>=0 && s-a-b<=k){
        i++;
      }
    }
  }

  printf("%d\n",i);
  return 0;
}
