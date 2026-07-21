#include<stdio.h>

int main(void) {
  int K,S;
  scanf("%d",&K);
  scanf(" %d",&S);
  int ans=0;

  for (int x = 0; x <=K; x++) {
    for (int y = 0; y <=K; y++) {
      if (S-x-y<=K && 0<=S-x-y) {
        ans+=1;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
