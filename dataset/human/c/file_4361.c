#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int main(){
  int n;
  scanf("%d", &n);
  
  int par = 0, max =0, tres = 0;
  
  for(int j = 0; j<n; ++j){
    int a, b;
    scanf("%d %d", &a, &b);
    
    if (a == b){
      par += 1;
      tres += 1;
      if (tres > max)
        max = tres;
    }
    else{
      par = 0;
      tres =0;
    }
  }
  if (max > 2)
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}
