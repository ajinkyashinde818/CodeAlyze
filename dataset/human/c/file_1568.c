#include <stdio.h>

int main(void){
  char moji1, moji2;

  scanf("%c %c", &moji1, &moji2);

  if(moji1 > moji2){
    printf(">\n");
  }else if(moji1 < moji2){
    printf("<\n");
  }else{
    printf("=\n");
  }

  return 0;
}
