#include<stdio.h>

int main(){
  int n,k;
  char s[11];

  scanf("%d",&n);
  scanf("%s",s);
  scanf("%d",&k);
  
  char a=s[k-1];
  int i;
  for(i=0;i<n;i++){
    if(s[i]!=a)
      printf("*");
    else
      printf("%c",s[i]);
  }
}
