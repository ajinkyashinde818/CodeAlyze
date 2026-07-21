#include <stdio.h>

int main(){
  int n, m, a, i;
  scanf("%d %d", &n, &m);
  n++;
  int dng[n];
  for(i = 0; i < n; i++){
    dng[i] = 0;
  }
  for(i = 0; i < m; i++){
    scanf("%d", &a);
    dng[a] = 1;
  }
  int ans[n];
  ans[0] = 1;
  ans[1] = !dng[1];
  for(i = 2; i < n; i++){
    if(!dng[i]){
      ans[i] = (ans[i - 1] + ans[i - 2]) % 1000000007;
    }else{
      ans[i] = 0;
    }
  }
  printf("%d\n", ans[n - 1]);
  return 0;
}
