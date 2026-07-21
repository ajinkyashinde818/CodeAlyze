#include <stdio.h>

int main(){
  
  char S[3];
  int i;
  for(i = 0 ; i < 3 ; i++){
    scanf("%s",&S[i]);
  }
  
  int a = 0 , b = 0 , c = 0 ;
  for(i = 0 ; i < 3 ; i++){
    if(S[i] == 'a') a++;
    if(S[i] == 'b') b++;
    if(S[i] == 'c') c++;
  }
  
  if(a == 1&&b == 1&&c == 1) printf("Yes");
  else printf("No");
  
  return 0 ;
  
}
