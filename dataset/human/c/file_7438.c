#include <stdio.h>
int main (void){
  int i;
  int x[10000];
  for(i = 0 ; i<10000 ; i++){
    scanf("%d\n",&x[i]);
    if(x[i] == 0){
      break;
    }
  }
  for(int j = 0; j<i ; j++){
      printf("Case %d: %d\n",j+1,x[j]);
  }
  return 0;
}
