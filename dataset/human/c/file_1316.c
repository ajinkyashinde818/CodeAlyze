#include <stdio.h>

int main(void){
  int n, m, a, b, i, btmp[200000], atmp[200000];
  scanf("%d%d", &n, &m);
  for(i=0; i<n; ++i){
    btmp[i] = 0;
    atmp[i] = 0;
  }
  for (i=0; i<m; ++i) {
    scanf("%d%d", &a, &b);
    if (a == 1){
      if (atmp[b-1] == 1){
	  printf("POSSIBLE\n");
	  return 0;
      }
      btmp[b-1] = 1;
    }
    if (b == n){
      if (btmp[a-1] == 1){
	printf("POSSIBLE\n");
	return 0;
      }
      atmp[a-1] = 1;
    }
  }
  printf("IMPOSSIBLE\n");
  return 0;
}
