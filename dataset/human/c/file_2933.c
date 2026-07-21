#include <stdio.h>

int main(void)
{
  int k,s,x,y,z,i,j;
  int ans = 0;
  
  scanf("%d %d", &k, &s);
  
  for (i = 0; i <= k; i++){
    for (j = 0; j <= k; j++){
      if ((k >= (s-(i+j)))&&((s-(i+j)) >= 0)){
        ans++;
      }
    }
  }
  
  printf("%d\n", ans);
  
  return 0;
}
