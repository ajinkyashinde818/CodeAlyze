#include <stdio.h>
#include <stdlib.h>

int main(void){
  int h,w;
  int i,j;
  char input[51][256];
  scanf("%d %d",&h,&w);

  for(i=0;i<h;i++)
    scanf("%s",input[i]);

  for(i=1;i<h;i++){
    for(j=1;j<w;j++){
      if(input[i][j]=='#'){
        if((input[i][j-1]=='.')&&(input[i-1][j]=='.')&&(input[i][j+1]=='.')&&(input[i+1][j]=='.')){
          printf("No\n");
          exit(0);
        }
      }
    }
  }

  printf("Yes\n");
  return 0;
}
