#include <stdio.h>

int
main(int argc, char *argv[])
{
  int n, m;
  scanf("%d %d", &n, &m);
  int flag1[200000] = {}, flagN[200000] = {};
  int a, b;
  for(int i = 0; i < m; i++){
    scanf("%d %d", &a, &b);
    if(a == 1 || b == 1) flag1[a + b - 2]++;
    if(a == n || b == n) flagN[a + b - n - 1]++;
  }

  int flag = 0;
  for(int i = 0; i < n; i++){
    if(flag1[i] > 0 && flagN[i] > 0){
      flag++;
      break;
    }
  }

  if(flag > 0) printf("POSSIBLE\n");
  else printf("IMPOSSIBLE\n");

  return 0;
}
