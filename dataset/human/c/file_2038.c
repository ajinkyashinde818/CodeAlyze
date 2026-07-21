#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compare_int(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int euclid(int a, int b){
  if(a < b){
    int tmp = a;a = b;b = tmp;
  }
  int r = a % b;
  if(r < 0) r += b;
  while(r != 0){
    a = b;b = r;r = a % b;
    if(r < 0) r += b;
  }
  return b;
}

int main(){
  int A,B,C;
  scanf("%d %d %d",&A,&B,&C);
  if(C<=A+B+1) printf("%d",C+B);
  else printf("%d",A+2*B+1);
  return 0;
}
