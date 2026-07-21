#include <stdio.h>

int
main(int argc, char *argv[])
{
  int k, s;
  scanf("%d %d", &k, &s);

  long int ans = 0;

  for(int x = 0; x <= (s < k ? s : k); x++){
    if(s - x > k && s - x <= 2 * k){
      ans += (long)(2 * k) + (long)x - (long)s + 1;
    }
    else if(s - x <= k){
      ans += (long)s - (long)x + 1;
    }
  }

  printf("%ld\n", ans);

  return 0;
}
