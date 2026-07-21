#include<stdio.h>
int main(){
  char s[4];
  int a=0,b=0,c=0;
  scanf("%s",s);
  for(int i=0;i<=2;i++){
    if(s[i]=='a' && a==0)a=1;
    if(s[i]=='b' && b==0)b=1;
    if(s[i]=='c' && c==0)c=1;
  }
  if(a==1 && b==1 && c==1){
    printf("Yes");
  }else{
    printf("No");
  }
  return 0;
}
