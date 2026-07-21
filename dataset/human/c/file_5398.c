#include <stdio.h>
#define min(a, b) ((a)>(b) ? (b) : (a))
int main(){
  int n, m, x;  scanf("%d %d %d", &n, &m, &x);
  int c[15];
  int a[15][15];
  for(int i=0; i<n; i++){
    scanf("%d", &c[i]);
    for(int j=0; j<m; j++)
      scanf("%d", &a[i][j]);
  }
  int i, j, bit, flag = 1;
  int ans = 1200005;
  for(bit=1; bit<(1<<n); bit++){
    int cost = 0;
    int algo[15] = {0};
    for(i=0; i<n; i++){
      if(bit & (1<<i)){
	cost += c[i];
	for(j=0; j<m; j++)
	  algo[j] += a[i][j];
      }
    }
    for(j=0; j<m; j++)
      if(algo[j] < x)
	break;
    if(j == m){
      ans = min(ans, cost);
      flag = 0;
    }
  }
  if(flag)  ans = -1;
  printf("%d\n", ans);
  return 0;
}
