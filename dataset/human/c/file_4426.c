#include<stdio.h>
int main(){
  int a = 0, n; scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int b, c; scanf("%d %d", &b, &c);
    if(b == c){
      a++;
      if(a == 3) break;
    }
    else a = 0;
  }
  if(a < 3) a = 0;
  a ? printf("Yes\n") : printf("No\n");
  return 0;
}
