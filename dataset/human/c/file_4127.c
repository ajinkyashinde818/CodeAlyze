#include <stdio.h>
#include <math.h>
int abs(int n){
    if(n > 0){
        return n;
    } else {
        return -n;
    }
}

int min(int a, int b){
    if(a > b){
        return b;
    } else {
        return a;
    }
}


int main(){
  int a, b, k;
  scanf("%d %d %d", &a, &b, &k);
  int n[min(a, b)];
  int count=0;
  for(int i = 1; i <= min(a, b); i++){
      if(a%i==0 && b%i==0){
          n[count]=i;
      //    printf("%d ", n[count]);
          count++;
      }
  }
  printf("%d", n[count-k]);
  return 0;
}
