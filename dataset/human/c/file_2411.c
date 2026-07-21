#include <stdio.h>

int main(void){
 int i = 0,m = 0,a = 0,b = 0,c = 0;
 char s[4];
 
 scanf("%s",s);
 
 for(m = 0;m < 3;m++){
  if(s[m] == 'a'){
   a++;
  }
  if(s[m] == 'b'){
   b++;
  }
  if(s[m] == 'c'){
   c++;
  }
 }
 
 if(a == 1 && b == 1 && c == 1){
  printf("Yes\n");
 }else{
  printf("No\n");
 }
 
 return 0;
}
