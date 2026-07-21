#include <stdio.h>


#define SIZE 200000


int main()
{
  int n, m, i, a, b;
  int aa[SIZE]={0}, bb[SIZE]={0};
  int flag=1;

  scanf("%d %d", &n, &m);
  for (i=0; i<m; i++){
    scanf("%d %d", &a, &b);
    if (a == 1) aa[b] = 1;
    if (b == n) bb[a] = 1;
  }

  for (i=0; i<SIZE; i++){
    if (aa[i] == 1 && bb[i] == 1){
      printf("POSSIBLE\n");
      flag--;
      break;
    }
  }

  if (flag) printf("IMPOSSIBLE\n");

  return 0;
}
