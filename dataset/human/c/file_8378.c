#include<stdio.h>
int main(void)
{
  int n, k, i;
  scanf("%d", &n);
  char s[n], a;
  scanf("%s", s);
  scanf("%d", &k);
  a=s[k-1];
  for(i=0;i<n;i++){
    if(s[i]!=a){
      s[i]='*';
    }
  }
  printf("%s", s);
  return 0;
}
