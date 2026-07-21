#include<stdio.h>

int main(void)
{
  int n,m;
  long x;
  scanf("%d %d %ld",&n,&m,&x);

  long c[n];
  long a[n][m];
  long long min=2000000LL;
  long long sum[1<<n][m];
  int flag=0;

  for(int i=0;i<n;i++){
    scanf("%ld",&c[i]);
    for(int j=0;j<m;j++){
      scanf("%ld",&a[i][j]);
    }
  }

  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<m;j++){
      sum[i][j]=0;
    }
  }



  for(int bit=1;bit<(1<<n);bit++){ //0~2^n-1
    int count=0;
    long long money=0;

    for(int i=0;i<n;i++){ //0~n-1
      if(bit&(1<<i)){
        money+=c[i];
        for(int j=0;j<m;j++){
          sum[bit][j]+=a[i][j];
        }
      }
    }

    for(int k=0;k<m;k++){
      if(sum[bit][k]>=x){
        count++;
      }
    }

    if(money<min&&count==m){
      flag=1;
      min=money;
    }
  }



  if(flag==1){
    printf("%lld\n",min);
  }else{
    puts("-1");
  }

  return 0;
}
