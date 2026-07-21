#include <stdio.h>
#define swap(type, x, y)  do{ type t = x; x = y; y = t; }while(0)

void quick(long array[], int left, int right){
  int pl = left, pr = right;
  long x = array[(pl + pr) / 2];
  do{
    while(array[pl] > x)  pl++;
    while(array[pr] < x)  pr--;
    if(pl <= pr){
      swap(long, array[pl], array[pr]);
      pl++, pr--;
    }
  }while(pl <= pr);
  if(pl < right)  quick(array, pl, right);
  if(pr > left)  quick(array, left, pr);
}

int main(){
  int n;  scanf("%d", &n);
  long a[300005];
  for(int i=1; i<=n*3; i++)
    scanf("%ld", a+i);
  quick(a, 1, n*3);
  long ans = 0;
  for(int i=n+1; i<=n*2; i++)
    ans += a[i];

  long anss = 0;
  for(int i=1; i<=n; i++)
    anss += a[i*2];

  // anss = anss>ans ? anss : ans;
  printf("%ld\n", anss);
  return 0;
}
