#include <stdio.h>

int main()
{
  int k,s;
  scanf("%d %d", &k, &s);
  int sum=0;
  for(int i=0;i<=k;i++){
    for(int j=0;j<=k ;j++){
      if(0 <= s-i-j && s-i-j <= k)
        sum++;
    }
  }
  printf("%d", sum);
  return 0;
}
