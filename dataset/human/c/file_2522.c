#include<stdio.h>
int main(){
  char s[4];
  int a=0,b=0,c=0,i;
  
  scanf("%s",s);
  
  for(i=0;i<3;i++){
    if(s[i]=='a')
      a++;
    if(s[i]=='b')
      b++;
    if(s[i]=='c')
      c++;
  }
  
  if(a==1&&b==1&&c==1)
    printf("Yes");
  else
    printf("No");
  
  return 0;
}
