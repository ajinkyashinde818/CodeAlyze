#include <stdio.h>

int main(void){
  char abc[4];

  scanf("%s",abc);

  if(abc[0]!=abc[1]){
    if(abc[1]!=abc[2]){
      if(abc[2]!=abc[0]){
        puts("Yes");
      }else{puts("No");}

    }else{puts("No");}

  }else{puts("No");}


  return 0;
}
