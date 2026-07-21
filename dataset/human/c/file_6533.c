#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void){
  int n, i, flag=0, v, prev;
  int *r, *min, m = 1000000000, max = 0, ans=0;

  scanf("%d",&n);
  r = malloc(sizeof(int)*n);
  min = malloc(sizeof(int)*n);

  //scanf("%d",&prev);
  
  for(i=0;i<n;i++){
    scanf("%d", &r[i]);
    if(m > r[i]){
      min[i] = r[i];
      m = r[i];
    }
    else min[i] = m;
  }
  max = r[n-1];
  ans = max-min[n-2];
  for(i=1;i<n-1;i++){
    if(r[n-1-i] > max) max = r[n-1-i];
    if(ans < max-min[n-2-i]) ans = max-min[n-2-i];
  }
  printf("%d\n",ans);

  return 0;
}
