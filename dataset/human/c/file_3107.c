#include <stdio.h>

int main()
{
  int kk, nn, max = -1;
  scanf("%d %d", &kk, &nn);
  int aa[nn], sa[nn];
  for(int ii = 0;ii < nn;ii++)
  {
    scanf("%d", &aa[ii]);
  }
  for(int ii = 0;ii < (nn - 1);ii++)
  {
    sa[ii] = aa[ii + 1] - aa[ii];
  }
  sa[nn - 1] = kk + aa[0] - aa[nn - 1];
  for(int ii = 0;ii < nn;ii++)
  {
    if(max < sa[ii])
      max = sa[ii];
  }
  max = kk - max;
  printf("%d\n", max);
  return 0;
}
