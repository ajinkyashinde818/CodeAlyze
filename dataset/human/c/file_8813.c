// ABC096-B
// OrangeStar

#include<stdio.h>

int main(void){
  int h, w;
  scanf("%d %d", &h, &w);

  char s[h+2][w+2];
  int i, j;

  for(i=1; i<h+1; i++){
    scanf("%s", &s[i][1]);
  }
  for(i=0; i<h+2; i++){
    s[i][0]='.';
    s[i][w+1]='.';
  }
  for(i=0; i<w+2; i++){
    s[0][i]='.';
    s[h+1][i]='.';
  }

  int check=0;

  for(i=0; i<h+2; i++){
    for(j=0; j<w+2; j++){
      if(s[i][j]=='#'){
        if(s[i-1][j]=='.' &&
           s[i+1][j]=='.' &&
           s[i][j-1]=='.' &&
           s[i][j+1]=='.'){
             check=1;
        }
      }
      if(check==1){
        break;
      }
    }
    if(check==1){
      break;
    }
  }

  if(check==1){
    printf("No\n");
  }else{
    printf("Yes\n");
  }

  return 0;
}
