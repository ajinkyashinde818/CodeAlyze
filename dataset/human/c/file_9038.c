#include <stdio.h>
#include <stdlib.h>
int main() {
  int N,K,temp=0,count=0;
  scanf("%d",&N);scanf("%d",&K);
  for (int i = 0; i < N; i++) {
    scanf("%d",&temp);
    if (temp>=K) {
      count++;
    }
  }
  printf("%d\n",count );
  return 0;
}
