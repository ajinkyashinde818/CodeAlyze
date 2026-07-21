#include <stdio.h>

int gcd_euclid(int u, int v) {
  int r;
  while (0 != v) {
    r = u % v;
    u = v;
    v = r;
    //printf("%d %d %d\n", r, u, v);
  }
  return u;
}

int main(void) {
	// your code goes here
	int a, b, x;
	scanf("%d %d %d", &a, &b, &x);
	int maxA = gcd_euclid(a, b);
	int i, j = 1, k;
	for(i = 1, k = 1; i <= x; i++, k++)
	{
	    if(maxA % k == 0)
	    {
	        j = maxA / k;
	    }
	    else
	    {
	        i--;
	    }
	    //printf("%d\n", i);
	}
	printf("%d\n", j);
	return 0;
}
