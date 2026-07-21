#include <stdio.h>

int main(){
  char ins[5];
  int flg=0;
  scanf("%s",ins);

  if(ins[0] == ins[1]){
    flg=1;
  }else if(ins[1] == ins[2]){
    flg=1;
  }else if(ins[2] == ins[0]){
    flg=1;
  }

  if(flg == 1){
    printf("No\n");
  }else{
    printf("Yes\n");
  }

  return 0;


}
