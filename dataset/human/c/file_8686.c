#include <stdio.h>

int main(void){
  int n;
  scanf("%d", &n);
  int a[100000];
  int count[100000] = {0};
  int ans = 0;
  int button;
  
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  
  button = a[0];
  count[0]++;
  ans++;
  
  while(1){
    if(button == 2){
      printf("%d\n", ans);
      return 0;
    }
    
    count[button - 1]++;
    if(count[button - 1] > 1){
      printf("-1\n");
      return 0;
    }
    
    button = a[button - 1];
    ans++;
  }
}
