#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 0;
  int h = 0;
  int destn = 0;
  int lx;
  int ly;
  int x;
  int y;
  int result = 0;
  int big;
  int small;
  int xs;
  int ys;
  int i = 0;

  scanf("%d%d%d", &n, &h, &destn);
  for(i = 0; i < destn; ++i) {
    scanf("%d%d", &x, &y);
    if(i >= 1) {
      xs = lx - x;
      ys = ly - y;
      if((xs > 0 && ys > 0) || (xs < 0 && ys < 0)) {
        xs = abs(xs);
        ys = abs(ys);
        if(xs > ys) {
          big = xs;
          small = ys;
        } else {
          big = ys;
          small = xs;
        }
        result += (small + big - small);
      } else {
        result += (abs(xs) + abs(ys));
      }
    }
    lx = x;
    ly = y;
  }
  printf("%d\n", result);
  return 0;
}
