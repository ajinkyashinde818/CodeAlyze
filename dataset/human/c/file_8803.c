#include<stdio.h>

int main(void){
  int h, w;
  int i, j;
  int flg=0;
  char can[52][52];

  scanf("%d%d", &h, &w);

  for(i=0; i<52; i++){
    for(j=0; j<52; j++){
      can[i][j] = '.';
    }
  }

  for(i=1; i<h+1; i++){
    scanf("%s", can[i]);
  }

  for(i=1; i<h+1; i++){
    for(j=1; j<w+1; j++){
      if(can[i][j]=='#'){
        if(can[i-1][j]=='.' && can[i+1][j]=='.' && can[i][j-1]=='.' && can[i][j+1]=='.'){
          flg = 1;
        }
      }
    }
  }

  if(flg==0){
    printf("Yes\n");
  }else{
    printf("No\n");
  }

  // for(i=0; i<h; i++){
  //   printf("%s\n", can[i]);
  // }

  // i = j = 2;
  // printf("%dの%dは%cです", i, j, can[i][j]);

  return 0;
}
