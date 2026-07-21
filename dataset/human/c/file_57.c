#include<stdio.h>
int main(){
 int r, g ,b, n, s = 0;
 scanf("%d %d %d %d", &r, &g, &b, &n);
 for(int i = 0; i <= n; i += r)
  for(int j = i; j <= n; j += g)
   if((n - j) % b == 0) s++;
 printf("%d", s);
}
