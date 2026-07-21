#include <stdio.h>

const int MAX = 10000;

int main(){
  int A[MAX];
  int length,work;
  length = 0;

  for(int i=0;i<MAX;i++){
    scanf("%d",&work);
    if(work != 0){
      A[i] = work;
      length++;
    } else {
      break;
    }
  }

  for(int i=0;i<length;i++){
    printf("Case %d: %d\n",i+1,A[i]);
  }

  return 0;
}
