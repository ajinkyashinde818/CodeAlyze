#include <stdio.h>

int main(void){
  int a,b,c,N;
  scanf("%d%d%d%d",&a,&b,&c,&N);

  int ans = 0;
  for (int i = 0; i <= N/a; i++) {
    if(i*a > N) break;
    for (int j = 0; j <= N/b; j++) {
      if(i*a+j*b > N) break;
      if((N-i*a-j*b)%c == 0) ans++;
    }
  }

  printf("%d\n",ans);

  return 0;
}
