#include<stdio.h>
#include<stdlib.h>
#define SIZE 200005

int from[SIZE] = {0};
int to[SIZE] = {0};

int main()
{
  int i;
  int n, m;
  int a, b;
  scanf("%d %d", &n, &m);

  for(i = 0; i < m; i++){
    scanf("%d %d", &a, &b);
    if(a == 1){
      from[b] = 1;
    }
    if(b == n){
      to[a] = 1;
    }
  }

  for(i = 0; i < SIZE; i++){
    if(from[i] && to[i]){
      printf("POSSIBLE\n");
      return 0;
    }
  }
  return 0*printf("IMPOSSIBLE\n");
}
