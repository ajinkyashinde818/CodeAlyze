#include <stdio.h>

int main(){
  int n, m;  scanf("%d%d", &n, &m);
  int from1[200003] = {0};
  int toN[200003] = {0};
  for(int i=0; i<m; i++){
    int f, t;  scanf("%d%d", &f, &t);
    if(f == 1)
      from1[t] = 1;
    else if(t == n)
      toN[f] = 1;

  }
  for(int i=1; i<=n; i++){
    if(from1[i] && toN[i]){
      printf("POSSIBLE\n");
      return 0;
    }
  }
  printf("IMPOSSIBLE\n");
  return 0;
}
