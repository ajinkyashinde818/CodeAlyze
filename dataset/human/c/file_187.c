#include<stdio.h>
#include<stdlib.h>
int main(){
  long long int i,n,a[100010],ans=0,k=0,min=1000000001;
  scanf("%lld\n",&n);
  for(i=0;i<n;i++){
    scanf("%lld ",&a[i]);
    ans=ans+abs(a[i]);
    if(a[i]<0){
      k++;
    }
    if(abs(a[i])<min){
      min=abs(a[i]);
    }
  }
  if(k%2==0){
    printf("%lld\n",ans);
  }
  else{
    printf("%lld\n",ans-min*2);
  }
  return 0;
}
