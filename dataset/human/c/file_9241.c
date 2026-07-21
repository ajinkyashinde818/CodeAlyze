#include <stdio.h>


int main(void){
  int n,k,count=0;
  scanf("%d",&n );
  scanf("%d",&k );

  int h[n];
  for (int i = 0; i < n; i++) {
    scanf("%d",&h[i] );
  }

  for (int i = 0; i < n; i++) {
    if (h[i]>=k) {
      count++;
    }
  }

  printf("%d\n",count );

  return 0;
}
