#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int n,d[105][5],count=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d %d",&d[i][0],&d[i][1]);
  }
  for(int i=0;i<n;i++){
    if(d[i][0]==d[i][1]) count++;
    if(d[i][0]!=d[i][1]) count=0;
    if(count>=3){
      printf("Yes");
      return 0;
    }
  }
  printf("No");
  return 0;
}
