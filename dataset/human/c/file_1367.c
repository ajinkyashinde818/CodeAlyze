#include <stdio.h>

int c[200000];
int table[200000] = {0};

int main(void){
  int N, M;
  scanf("%d %d", &N, &M);

  int a, b;
  int i, count=0;

  for(i=0;i<M;i++){
    scanf("%d %d", &a, &b);
    if(b == N)
      table[a] = 1;
    if(a == 1){
      c[count] = b;
      count++;
    }
  }

  int possible=0;
  for(i=0;i<count;i++){
    if(table[c[i]] == 1){
      possible = 1;
      break;
    }
  }

  if(possible == 1)
    printf("POSSIBLE\n");
  else
    printf("IMPOSSIBLE\n");

  return 0;
}
