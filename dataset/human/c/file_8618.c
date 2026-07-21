#include <stdio.h>

int main(){
  int n, i, turn_on=0, count=0;
  scanf("%d", &n);
  int a[n];
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  for(i=0; i<n; i++){
    turn_on=a[turn_on]-1;
    count++;
    if(turn_on==1){
      printf("%d\n", count);
      return 0;
    }
  }
  printf("-1\n");

  return 0;
}
