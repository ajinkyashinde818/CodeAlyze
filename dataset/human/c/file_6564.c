#include <stdio.h>

int main(){
  int N,i,num,Min,Max=0;


  scanf("%d",&N);
  scanf("%d",&num);
  Min=num;
  scanf("%d",&num);
  Max=num-Min;
  if(Min>num)Min=num;
  for(i=2;i<N;i++){
    scanf("%d",&num);
    if(Max<num-Min)Max=num-Min;
    if(Min>num)Min=num;
  }
  printf("%d\n",Max);
  
  return 0;
}
