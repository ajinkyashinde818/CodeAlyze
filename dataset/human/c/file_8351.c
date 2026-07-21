#include <stdio.h>

int main(void)
{
  int n, k, i;
  char s[n], t;

  scanf("%d",&n);
  scanf("%s",s);
  scanf("%d",&k);

  t = s[k-1];

  for(i=0;i<n;i++){
    if(s[i]!=t){
      s[i]='*';
    }
  }

  printf("%s",s);

  return 0;
}
