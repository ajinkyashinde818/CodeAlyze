#include <stdio.h>

bool ck[3];
int main(){
  char s[3];
  scanf("%s",s);
  for(int i=0;i<3;i++){
    if(s[i]=='a') ck[0]=true;
    else if(s[i]=='b') ck[1]=true;
    else if(s[i]=='c') ck[2]=true;
  }
  if(ck[0]&&ck[1]&&ck[2]) printf("Yes");
  else printf("No");
}
