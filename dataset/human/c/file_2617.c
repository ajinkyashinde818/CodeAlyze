#include<stdio.h>
int main(){
  char s[4];
  scanf("%s",s);
  if((s[0]-'a')+(s[1]-'a')+(s[2]-'a')==3 &&
     (s[0]-'a'+1)*(s[1]-'a'+1)*(s[2]-'a'+1)==6)
    printf("Yes");
  else
    printf("No");
  return 0;
}
