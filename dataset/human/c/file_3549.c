#include<stdio.h>


int main(){

  int n, i, j, cnt, max=0;
  int p[100];

  scanf("%d", &n);

  for(i=0;i<n;i++) scanf("%d", &p[i]);

  for(i=1;i<=100;i++){
    cnt=0;
    for(j=0;j<n;j++){
      if(i<=p[j]) cnt++;
    }
    if(cnt>=i&&max<i) max=i;
  }

  printf("%d\n", max);

  return 0;
}
