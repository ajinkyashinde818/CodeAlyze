#include <stdio.h>
#include <string.h>

int main(void){

  int N = 0;
  int K = 0;
  scanf("%d\n",&N);
  scanf("%d\n",&K);
  int inputData = 0;
  int result = 0;


  for(int i = 0;i < N;i++){
    scanf("%d\n",&inputData);
    if(inputData >= K){
      result++;
    }
  }

  printf("%d\n",result);

}
