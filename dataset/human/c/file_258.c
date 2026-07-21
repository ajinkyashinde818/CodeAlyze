#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
  int n,i,tmp,cnt=0,min=1e9;
  long long int sum=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(a[i]<0){
      tmp=a[i]*(-1);
      sum+=tmp;
      cnt++;
      if(min>tmp) min=tmp;
    }else{
      sum+=a[i];
      if(min>a[i]) min=a[i];
    }
  }
  if(cnt%2==0){
    printf("%lld\n",sum);
  }else{
    printf("%lld\n",sum-(2*min));
  }
  return 0;
}
