#include <stdio.h>

int main(void){
  int w, h, n;
  int i, xb, yb, xn, yn, xgap, ygap, count = 0;
  scanf("%d%d%d", &w, &h, &n);
  //printf("%d %d %d\n", w, h, n);
  for(i = 0; i < n; i++){
    if(i != 0){
      xb = xn;
      yb = yn;
    }
    scanf("%d%d", &xn, &yn);
    //printf("%d %d\n", xn, yn);
    if(i != 0){
      xgap = xn - xb;
      ygap = yn - yb;
      //printf("count:%d\n", count);
      //printf("xgap : %d ygap : %d\n", xgap, ygap);
      if(xgap == 0){ count += ygap > 0 ? ygap : -ygap; continue; }
      if(ygap == 0){ count += xgap > 0 ? xgap : -xgap; continue; }
      if(ygap > 0 && xgap > 0){
	count += ygap > xgap ? ygap : xgap;
	//count += (ygap - xgap) > 0 ? ygap - xgap : xgap - ygap;
	continue;
      }
      if(ygap < 0 && xgap < 0){
	count -= ygap < xgap ? ygap : xgap;
	//count -= (ygap - xgap) < 0 ? ygap - xgap : xgap - ygap;
	continue;
      }
      if(ygap > 0){ count += ygap - xgap; continue; }
      if(xgap > 0){ count += xgap - ygap; continue; }
    }
  }
  printf("%d\n", count);

  return 0;
}
