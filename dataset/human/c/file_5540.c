#include<stdio.h>
int sosu[150000],sum,flg=0;
main(){
  int n=150000,i,j;
  while(1){
  scanf("%d",&n);
  if(n==0)break;
  flg=0;
  for(i=0;i<=150000;i++)sosu[i]=0;
    sum=0;
    for(i=2;flg<n;i++){
    if(sosu[i]==0){
      flg++;
      sum+=i;
    for(j=2;i*j<=150000;j++){
      sosu[i*j]=1;
    }
    }
  }

     printf("%d\n",sum);
  }
  return 0;
}
