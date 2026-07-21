#include <stdio.h>

int main(){
  char S[4];
  int d[4]={1,1,1},c=1;
  scanf("%s",S);
  for(int i=0;i<3;i++){
    if(d[S[i]-'a']!=1)
      c=0;
    d[S[i]-'a']--;
  }
  if(c==1) printf("Yes\n");
  else printf("No\n");
  return 0;
}
