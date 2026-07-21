#include <stdio.h>

int gcd(int a, int b) {
  int temp;
  if(a < b) { temp = a; a = b; b = temp; }
  while(b != 0) {
    a %= b;
    temp = a; a = b; b = temp;
  }
  return a;
}
    

int main()
{
  int a, b, k, max;
  scanf("%d %d %d", &a, &b, &k);
  max = gcd(a, b);
  while( max > 0 && k > 0) {
    if( a%max == 0 && b%max == 0) { 
      --k; if(k == 0) break; }
    --max;
  }
  printf("%d\n", max);
  return 0;
}
