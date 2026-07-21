#include<stdio.h>

int main(){
  long long n,cnt=0,tmp,ans=0,min=10000000;
  int a[100001];
  min=1000000;
  scanf("%lld",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
//    min=(min>abs(a[i]))?abs(a[i]):min;
    if(a[i]<0) {
      cnt++;
      a[i]=-1*a[i];
    }
 //   printf("%d\n",a[i]);
    if(min>a[i]){
      min=a[i];
    }
 //   printf("%lld\n",min);
    ans+=a[i];
  }
  if(cnt%2==0){
    printf("%lld",ans);
    return 0;
  }
  else {
//    printf("%lld\n",min);
    printf("%lld",ans-2*min);
  }
  return 0;
}
