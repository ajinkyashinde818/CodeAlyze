#include <stdio.h>

int main(){
   int i,n,k;
   char s[11];
    
   scanf("%d",&n);
   scanf("%s",s);
   scanf("%d",&k);
   for (i=0;i<n;i++)
      if (s[i]!=s[k-1]) s[i]='*';
   puts(s);
   return 0;
}
