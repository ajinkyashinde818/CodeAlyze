#include<stdio.h>
int main(void){
  char s[3];
  scanf("%s",s);
  int i;
  if(s[0]!=s[1] && s[1]!=s[2] && s[2]!=s[0]){
    for(i=0;i<3;i++){
      if(s[i]=='a' || s[i]=='b' || s[i]=='c'){
        if(i==2){
        puts("Yes");
        }
      }
      else{
        if(i==2){
        puts("No");
        }
      }
    }
  }
  else{
    puts("No");
  }
    return 0;
  }
