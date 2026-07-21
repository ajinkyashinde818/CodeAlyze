#include<stdio.h>

int main(void){
  int n,k,i;
  char target;
  scanf("%d",&n);
  char s[n];
  scanf("%s",s);
  scanf("%d",&k);
  target = s[k-1];
  for(i=0;i<n;i++){
    if(s[i]!=target){
      s[i] = '*';
    }
  }
  printf("%s",s);
  return 0;
}
