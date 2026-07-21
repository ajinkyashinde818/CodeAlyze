#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
  if(a>b){
    return b;
  }else{
    return a;
  }
}

int main(void){
  int i,l;
  long int tmp;
  int n;
  long long a[120000];
  int count=0;
  long long sum=0;


  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%lld",&a[i]);
  }

  for(i=0;i<n;i++){
    if(a[i]<0){
      count++;
      a[i]=abs(a[i]);
    }
  }
  if(count%2==0){

    for(i=0;i<n;i++){
      sum+=a[i];
    }
    printf("%lld",sum);
  }else if(count%2!=0){
      long long minmax=a[0];
    for(i=0;i<n;i++){
      minmax=min(minmax,a[i]);
    }

    for(i=0;i<n;i++){
      sum+=a[i];
    }
    sum=sum-(minmax*2);
    printf("%lld",sum);
  }


  return 0;
}
