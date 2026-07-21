#include <stdio.h>
int main(void){
  int a,b,match = 0;
  scanf("%d %d",&a,&b);
  char A[a][a],B[b][b];
  for(int i = 0;i < a;i++){
    scanf("%s",&A[i]);
  }
  for(int i = 0;i < b;i++){
    scanf("%s",&B[i]);
  }
  for(int i = 0;i < a;i++){
    for(int ii = 0;ii < a;ii++){
      int flag = 1;
      for(int j = 0;j < b;j++){
        for(int k = 0;k < b;k++){
          if(A[i + j][ii + k] != B[j][k]){
            flag = 0;
          }
        }
      }
      if(flag == 1){
        match = 1;
      }
    }
  }
  if(match == 0){
    printf("No");
  }else{
    printf("Yes");
  }
  return 0;
}
