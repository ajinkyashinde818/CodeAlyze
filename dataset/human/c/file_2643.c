#include<stdio.h>

int main(){
  char s[4];
  int check_a = 0, check_b = 0, check_c = 0, i;
  
  scanf("%s", s);
  for (i = 0; i < 3; i++){
    if(s[i] == 'a'){
      check_a = 1;
    }
    if(s[i] == 'b'){
      check_b = 1;
    }
    if(s[i] == 'c'){
      check_c = 1;
    }
  }
    
    if(check_a == 1 && check_b == 1 && check_c == 1){
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
