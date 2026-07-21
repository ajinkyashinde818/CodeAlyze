#include<stdio.h>

int main(int argc, char *argv[]){

  int n;
  scanf("%d", &n);

  int a[n];
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  int out = -1;
  int index = a[0];

  int loop_chk[n];
  for(int i=0; i<(sizeof(loop_chk)/sizeof(loop_chk[0])); i++){
    loop_chk[i] = 0;
  }

  for(int i=1; i<n; i++){
    //printf("i=%d, index=%d\n", i, index);
    if(index == 2){
      out = i;
      break;
    }
    if(loop_chk[index] == 1){
      break;
    }else{
      loop_chk[index] = 1;
    }
    index = a[index - 1];
  }

  printf("%d\n", out);

  return 0;
}
