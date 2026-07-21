#include<stdio.h>

int main(void){
  int n;
  long k;
  scanf("%d%ld", &n, &k);

  int a[n+1];
  int done[n+1];
  a[0] = 0;
  done[0] = -1;
  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
    done[i] = 0;
  }

  long outCycle = 0;
  long cycle = 0;
  long startCycle = 0;

  int now = 1;
  int next = 0;
  done[now] = 0;

  // printf("%d(%d)", now, done[now]);
  for(long i = 1; i <= k; i++){
    next = a[now];
    if(done[next]){
      outCycle = done[next];
      cycle = i - done[next];
      startCycle = next;
      // printf("-> %d(%d)", next, done[next]);
      break;
    }
    now = next;
    done[now] = i;
    // printf("->%d(%d)", now, done[now]);
  }
  // printf("\n");
  // printf("out:%d, cycle:%d, star:%d\n", outCycle, cycle, startCycle);
  if(cycle){
    long kc = k - outCycle;
    long end = kc % cycle;
    if(end == 0)
      end = cycle;
    now = startCycle;
    for(long i = 0; i < end; i++){
      now = a[now];
    }
  }
  // printf("\n");
  printf("%d\n", now);
}
