#include<stdio.h>

int main(){
  int r, g, b, n;
  int cnt = 0;
  scanf("%d %d %d %d\n", &r, &g, &b, &n);
  int x = n / r;
  for(int i=x;i>=0;i--){
    int y = (n - (i * r)) / g;
    for(int j=y;j>=0;j--){
      int z = n - (i * r) - (j * g);
      if(z % b == 0){
        cnt++;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
