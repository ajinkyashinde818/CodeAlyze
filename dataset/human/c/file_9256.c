#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int n,k,i,count=0;
  int *h;

  scanf("%d%d",&n,&k );

  h = calloc(n,sizeof(int));

  for(i=0; i<n; i++){
    scanf("%d", &h[i]);
      if(h[i] >= k)
        count++;
  }

  printf("%d", count);
  free(h);
  return 0;
}
