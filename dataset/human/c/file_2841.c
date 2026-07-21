#include <stdio.h>

int ans = 0;

void dfs(int array[], int k, int s){
  if(array[0] == 2){
    int sum = 0;
    for(int i=1; i<=3; i++)
      sum += array[i];
    if(s-k <= sum  &&  sum <= s)
      ans++;
    return;
  }

  for(int i=0; i<=k; i++){
    array[++array[0]] = i;
    dfs(array, k, s);
    array[0]--;
  }
}
int main(){
  int k, s;  scanf("%d %d", &k, &s);
  int array[4] = {0};
  dfs(array, k, s);

  printf("%d\n", ans);

  return 0;
}
