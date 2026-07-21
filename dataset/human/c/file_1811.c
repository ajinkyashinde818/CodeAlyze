#include<stdio.h>
int main(void)
{
  int n,a[21],b[21],c,d[21]={},sum=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=0;i<n-1;i++){
    if(a[i]+1==a[i+1]){
      d[a[i]-1]=1;
    }
  }/*
  for(int i=0;i<n-1;i++){
    printf("%d",d[i]);
  }
  puts("");*/

  for(int i=0;i<n;i++){
    scanf("%d",&b[i]);
    sum+=b[i];
  }

  //printf("\n%d\n",sum);
  for(int i=0;i<n-1;i++){
    scanf("%d",&c);
    if(d[i]==1){
      sum+=c;
    }
  }
  printf("%d",sum);
  return 0;

}
