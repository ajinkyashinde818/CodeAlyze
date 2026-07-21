#include <stdio.h>

int main(){
   char s[100001];
   long sum;
   int i,n,c[26];
    
   scanf("%d",&n);
   scanf("%s",s);
   for (i=0;i<26;i++) c[i]=0;
   for (i=0;i<n;i++) c[s[i]-'a']++;
   sum=0;
   for (i=0;i<26;i++) {
      if (c[i]==1) sum=(sum*2+1)%1000000007;
      else if (c[i]>1 && sum==0) sum=c[i];
      else if (c[i]>1) sum=(sum*(c[i]+1)+c[i])%1000000007;
   }
   printf("%ld\n",sum);
   return 0;
}
