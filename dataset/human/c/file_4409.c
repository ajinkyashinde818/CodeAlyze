#include <stdio.h>
#include <stdlib.h>
int main(){
  int N,i,count;
  count=0;
  scanf("%d",&N);
  int A[N+1],B[N+1];
  for(i=0;i<N;i++){
    scanf("%d %d",&A[i],&B[i]);
    if(A[i]==B[i]){
      count++;
      if(count>2){
        printf("Yes");
        return 0;
      }
    }
    else count=0;
  }
  printf("No");
  return 0;
}
