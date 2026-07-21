#include<stdio.h>
int main(void){
  int N; //人数
  scanf("%d",&N);
  int K; //身長制限
  scanf("%d",&K);
  int int_hight[N]; //身長

  for(int i=0; i<N; i++){
    scanf("%d",&int_hight[i]);
  }

  int CountHight=0;
  for(int i=0; i<N; i++){
    if(int_hight[i]>=K){
      CountHight++;
    }
  }
  printf("%d\n",CountHight);

}
