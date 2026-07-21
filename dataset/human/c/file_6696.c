#include <stdio.h>

int main(void) {
  int i, j, n, m;
  while ( 1 ) {
    scanf("%d%d", &n, &m);
    if(!n && !m) break;
    char flag[n];
    for(i = 0; i < n; ++i) flag[i] = 0;
    int a[m], b[m];
    for(i = 0; i < m; ++i) {
      scanf("%d%d", &a[i], &b[i]);
      a[i]--, b[i]--;
      if(!a[i]) flag[b[i]] = 1;
      if(!b[i]) flag[a[i]] = 1;
    }
    flag[0] = 1;
    for(i = 1; i < n; ++i) {
      if(flag[i] == 1)
      for(j = 0; j < m; ++j) {
        if(a[j] == i && !flag[b[j]]) flag[b[j]] = 2;
        if(b[j] == i && !flag[a[j]]) flag[a[j]] = 2;
      }
    }
    int ans = -1;
    for(i = 0; i < n; ++i) if(flag[i]) ++ans;
    //for(i = 0; i < n; ++i) printf("%d ", flag[i]);
    printf("%d\n", ans);
  }
  return 0;
}
