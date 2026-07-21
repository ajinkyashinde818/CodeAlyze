#include <stdio.h>
#define DATA 10000
int main(){
    int i, j;
    int x;
    int data[DATA];

    for(j=0; j<DATA; j++){
      scanf("%d", &x);
      data[j] = x;
      if(x == 0){
        break;
      }
    }

    for(i=0; i<j; i++){
      printf("Case %d: %d\n", i+1, data[i]);
    }

}
