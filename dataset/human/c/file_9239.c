#include <stdio.h>
int main()
{
  long long int i, j;
  long long int a,b=0,k=0;
  scanf("%lld %ldd",&a,&b);
  int h[a];
  for (i = 0; i < a; i++) {
    scanf("%d",&h[i]);
  }
  for (i = 0; i < a; i++) {
    if (h[i]>=b) {
      k++;
    }
  }
  printf("%d\n",k);
  return 0;
}
