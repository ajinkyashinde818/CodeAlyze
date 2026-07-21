#include <stdio.h>
#include <string.h>

int main()
{
  int n,k;
  char s[15];
  scanf("%d",&n);
  scanf("%s",s);
   scanf("%d",&k);
  int i;
  k--;
  for(i=0;i<n;i++)
    if(s[i] != s[k])
      s[i] = '*';

  printf("%s\n",s);
  
  return 0;
}
