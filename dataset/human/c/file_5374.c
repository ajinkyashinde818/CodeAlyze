#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef long long ll;

int main(){
  int n,m,x;
  int c[14];
  int a[14][14];
  int i,j,k,l;
  ll min = 100100100;
  int sum[14];
  int flag = 0;
  ll value;

  scanf("%d %d %d", &n, &m, &x);

  for(i = 0;i < n;i++){
    scanf("%d", &c[i]);
    for(j = 0;j < m;j++) scanf("%d", &a[i][j]);
  }

  for(i = 0;i < (1 << n);i++){
    for(l = 0;l < m;l++) sum[l] = 0;
    flag = 0;
    value = 0;

    for(j = 0;j < n;j++){
      if(i & (1 << j)){
        for(k = 0;k < m;k++){
          sum[k] += a[j][k];
        }
        value += c[j];
      }
    }

    for(l = 0;l < m;l++){
      if(sum[l] < x){
        flag = 1;
      }
    }

    if(flag == 0){
      if(min > value) min = value;
    }
  }

  if(min == 100100100) printf("-1\n");

  else printf("%lld\n", min);

  return 0;
}
