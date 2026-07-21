#include<stdio.h>
#include<string.h>

int main(){
  
  int n,k;
  char s[11];
  
  scanf("%d\n%s\n%d\n",&n,&s,&k);
  
  char letter;
  letter=s[k-1];
    
  for(int i; i<strlen(s); i++){
    if(letter==s[i]){
     printf("%c",letter);
    }else{
     printf("*");
    }
  }
  
  return 0;
}
