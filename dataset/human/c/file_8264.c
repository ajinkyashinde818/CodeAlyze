#include <stdio.h>
int main(){
 int n,pl,i;
 scanf("%d",&n);
  char s[n+1];
  scanf("%s\n%d",s,&pl);
  for(i=0;i<n;i++){
    if(s[i]==s[pl-1])printf("%c",s[i]);
    else printf("*");
  }
}
