#include <stdio.h>
#include <string.h>

int main(void){
  int n,d[110][2],i,count=0;
  if(scanf("%d",&n) == EOF) return 1;
  for(i=0;i<n;i++) if(scanf("%d %d",&d[i][0],&d[i][1]) == EOF) return 1;
  
  for(i=0;i<n;i++){
    if(d[i][0] == d[i][1]) count++;
    else count=0;
    if(count >= 3){
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  
  return 0;
}
