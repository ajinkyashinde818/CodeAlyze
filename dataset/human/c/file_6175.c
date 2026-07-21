#include <stdio.h>
#include <stdlib.h>

main() {

  int i;
  int n;       //データ数
  int *r;      //データ配列用ポインタ
  int maxv, minv; //最大利益

  scanf("%d", &n);
  
  r = (int *)malloc(sizeof(int) * n);

  for( i=0; i<n; i++) {
    scanf("%d", &r[i]);
  }

  maxv = r[1] - r[0];
  minv = r[0];

  for( i=1; i<n; i++) {
    if(maxv < r[i]-minv) {
      maxv = r[i] - minv;
    }
    if(minv > r[i]) {
      minv = r[i];
    }
  }

  free(r);

  printf("%d\n", maxv);

  return 0;

}
