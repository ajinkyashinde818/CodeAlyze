#include <stdio.h>
#include <stdlib.h>

int main()
{
  int r, i, n, rmin, dmax;
  char buf[16];
  buf[15]='\0';
  buf[14]='\n';
  fgets(buf, 16, stdin);
  n = atoi(buf);
  fgets(buf, 16, stdin);
  rmin = atoi(buf);
  fgets(buf, 16, stdin);
  r = atoi(buf);
  dmax = r-rmin;
  if (rmin>r) rmin=r;
  for (i=0; i<n-2; i++) {
    fgets(buf, 16, stdin);
    char *p = buf;
    for (r=0; *p>='0'; p++) r = r * 10 + *p - '0';
    if (dmax < r-rmin) dmax = r-rmin;
    if (rmin>r) rmin=r;
  }
  if (dmax==0) {
    fputs("0\n", stdout);
  } else {
    int sign=0;
    if (dmax<0) {
      sign=1;
      dmax=-dmax;
    }
    for (i=13; dmax>0; i--, dmax/=10)   buf[i] = '0' + (dmax%10);
    if (sign) buf[i--]='-';
    fputs(buf+i+1, stdout);
  }
  return 0;
}
