#include<stdio.h>

int main(void){
  int a, b, k;
  scanf("%d %d %d", &a, &b, &k);
  int C[100];
  int c = 0, count = 0;
  if(a >= b){
    for(int i = 1; i <= a; i++)
      if(a%i == 0 && b%i == 0){
        C[c++] = i;
        count++;
      }
  }
  else {
    for(int i = 1; i <= b; i++)
      if(a%i == 0 && b%i == 0){
        C[c++] = i;
        count++;
      }
    }
  printf("%d", C[count-k]);
}
