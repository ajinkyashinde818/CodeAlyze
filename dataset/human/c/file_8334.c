#include<stdio.h>
int main(void){
  int n;
  char s[10];
  int k;
  int i;

  scanf("%d",&n);
  scanf("%s",s);
  scanf("%d",&k);

  char l;//交換しない文字;
  l=s[(k-1)];

  for(i=0;i<n;i++){

    if(s[i]!=l){
      s[i]='*';
    }

  }

  printf("%s",s);

  return 0;
}
