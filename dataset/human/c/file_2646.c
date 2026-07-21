#include<stdio.h>
int main(void){
  char s[3];
  int i,aa=0,bb=0,cc=0;
  scanf("%s",s);
  for(i=0;i<3;i++){
    if(s[i]=='a') aa++;
    if(s[i]=='b') bb++;
    if(s[i]=='c') cc++;    
  }
  if(aa==1&&bb==1&&cc==1)
    printf("Yes");
  else printf("No");
  return 0;
}
