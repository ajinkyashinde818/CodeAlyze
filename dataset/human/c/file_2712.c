#include <stdio.h>

int main()
{
  int k, s;
  int x, y, z;
  int answer = 0;
  scanf("%d%d", &k, &s);
  //   printf("k%d,s %d\n", k, s); 
  //      printf("until k : %d\n", k); 

  for (x = 0; x <= k; x++) {
    for (y = 0; y <= k; y++) {
      z = s - x - y;
      if ((z < 0) || (z > k))
	continue;
      //            printf("x%d, %d, %d, %d\n", x, y, z, s);
      answer++;
      
    }
  }

  printf("%d", answer);
}
