#include<stdio.h>
long long step_variation(long long n){
  long long onebf = 0;
  long long twobf = 0;
  long long result = 0;
  long long oldresult = 0;
  long long i = 0;
  if(n==0){
    return 1;
  }else if(n==1){
    return 1;
  }else if(n==2){
    return 2;
  }else{
    onebf=2;
    twobf=1;
    for(i=0;i<n-2;i++){
      result = (onebf + twobf)%1000000007;
      twobf = onebf;
      onebf = result;
    }
    return result%1000000007;
  }
}

int main(){
  int n=0;
  int m =0;
  int a[100000] ={};
  int b[100000] = {};
  long long i = 0;
  long long total = 0;
  int successable = 0;
  scanf("%d %d",&n,&m);
  
  for(i=0;i<m;i++){
    scanf("%d",&a[i]);
  }
  
  //printf("%ld/",step_variation(5));
  for(i=0;i<m;i++){
    if(i==0){
      b[i] = a[i]-1;
    }else{
      b[i] = a[i] - a[i-1] -2;
    }
  }
  b[m] = (n-2)-a[m-1]+1;
  if(m==0){
    b[0] = n;
  }
  
  /*for(i=0;i<=m;i++){
    printf("%ld/",b[i]);
  }*/
  total = 1;
  for(i=0;i<m+1;i++){
    total = (total * step_variation(b[i]))%1000000007;
  }
  for(i=0;i<m-1;i++){
    if(a[i]+1 == a[i+1]){
        total = 0;
    }
  }
  printf("%lld",total);
  
  return 0;
}
