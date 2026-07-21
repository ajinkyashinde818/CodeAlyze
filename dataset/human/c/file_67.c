#include <stdio.h>
#define swap(type, x, y)  do{ type t = x; x = y; y = t; }while(0)

int main(){
  long a[4] = {0}, n;
  for(int i=1; i<=3; i++)  scanf("%ld", a+i);
  scanf("%ld", &n);
  
  for(int i=1; i<3; i++)
    for(int j=i+1; j<=3; j++)
      if(a[i] < a[j])
	swap(long, a[i], a[j]);
  long ans = 0;
  for(long i=0; i<=n/a[1]; i++){
    for(long j=0; j<=(n-a[1]*i)/a[2]; j++){
      if((n-a[1]*i-a[2]*j) % a[3] == 0)
	ans++;
    }
  }
  printf("%ld\n", ans);
  return 0;
}
