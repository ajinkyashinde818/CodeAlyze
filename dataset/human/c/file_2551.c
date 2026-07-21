#include <stdio.h>

int main(void){
  char S[3];
  int flag[3] = {0,0,0};

  scanf("%s",S);

  for(int i = 0;i < 3;i++){
    switch(S[i]){
      case 'a':
        flag[0] = 1;
        break;
      case 'b':
        flag[1] = 1;
        break;
      case 'c':
        flag[2] = 1;
        break;
    }
  }

  for(int i = 0;i < 3;i++){
    if(!flag[i]){
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");
  return 0;
}
