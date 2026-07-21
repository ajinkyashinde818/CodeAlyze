#include <stdio.h>

int main(void)
{
	int n, d, x, i, j, c;
  int a[110];
  int b;
	scanf("%d %d %d",&n, &d, &x);

  for(i = 0; i < n ; i++){/*入力*/
		scanf("%d", &a[i]);
		}

  c = 0;

  for (j  = 0; j < n; j++) {
    b = 0;

    for ( i = 1; b <= d ; i++) {
      b = a[j] * i - a[j] + 1;
      if (b <= d) {
      c++;
      }
    }

}
	printf("%d\n", c + x);
	return 0;
}
