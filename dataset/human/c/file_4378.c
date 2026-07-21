#include <stdio.h>

int main(void){
  int n;
  scanf("%d", &n);
  int x[n],y[n];
  
  for(int i=0;i<n;i++){
    scanf("%d %d", &x[i], &y[i]);
  }

  for(int i=0;i<n-2;i++){
    if((x[i] == y[i]) && (x[i+1] == y[i+1]) &&(x[i+2] == y[i+2])){
      printf("Yes\n");
      return 0;
    }
  }

  printf("No\n");

  return 0;
}
