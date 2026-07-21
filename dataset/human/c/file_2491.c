#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
  int i,j;
  int n,a=0,b=0,c=0;
  char s[10];
  scanf("%s",s);
  for(i=0;i<3;i++){
    if(s[i]=='a') a++;
    if(s[i]=='b') b++;
    if(s[i]=='c') c++;
  }
  if(a==1 && b==1 && c==1)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
