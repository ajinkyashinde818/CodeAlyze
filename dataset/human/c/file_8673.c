#include <stdio.h>
#define MAX 100001
int main(void){
  int i, N, c, now, a[MAX];
  scanf("%d", &N);

  for(i=0;i<N;i++){
    scanf("%d", &(a[i]));
    a[i]--;
  }

  c = 0;
  now = 0;
  while(1){
    if(now == 1){
      printf("%d\n", c);
      break;
    }
    if(c >= N){
      printf("-1\n");
      break;
    }
    c++;
    now = a[now];
  }
  return 0;
}
