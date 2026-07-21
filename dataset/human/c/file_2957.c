#include <stdio.h>

int main(void){
  int k, s;
  scanf("%d%d", &k, &s);
  int ans = 0;
  
  for(int i = 0; i <= k; i++){
    for(int j = 0; j <= k; j++){
      if(0 <= s - i - j && s - i - j <= k) ans++;
    }
  }
  
  printf("%d\n", ans);
  return 0;
}
