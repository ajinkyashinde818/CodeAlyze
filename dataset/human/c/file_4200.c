#include <stdio.h>
int main(void){
  long long n, m, a[99999] = {0}, p = 0, pre1[3000] = {0}, pre2[3000] = {0}, now[3000] = {0};
  scanf("%lld %lld", &n, &m);getchar();
  for(int i = 0; i < m; i++){
    scanf("%lld", &a[i]);getchar();
  }
  for(int i = 1; i <= n; i++){
    if(i == 1){
      now[0] = 1;
    }else if(i == 2){
      if(a[p - 1] == 1){
        now[0] = 1;
      }else{
        now[0] = 2;
      }
    }else{
      for(int j = 0; j < 3000; j++){
      	now[j] = pre1[j] + pre2[j];
      }
    }
    if(a[p] == i){
      for(int j = 0; j < 3000; j++){
      	now[j] = 0;
      }
      p++;
    }
    for(int j = 0; j < 2999; j++){
      if(now[j] >= 1000000000){
        now[j + 1]++;
        now[j] %= 1000000000;
      }
    }
    for(int j = 0; j < 3000; j++){
    	pre2[j] = pre1[j];
    	pre1[j] = now[j];
    }
  }

  for(int i = 2999; i >= 0; i--){
    now[i] %= 1000000007;
    if(i == 0){break;}
    now[i - 1] += now[i] * 1000000000;
  }
  printf("%lld\n", now[0]);
  return 0;
}
