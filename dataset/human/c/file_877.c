#include<stdio.h>
int main(){
  long long n,i,j,c,ans=0;
  scanf("%lld",&n);
  for(i=2;i*i<n;i++){
    for(c=0;n%i==0;c++)n/=i;//printf("%lld\n",c);
    for(j=0;j*(j+1)/2<=c;j++);
    ans+=j-1;
  }//printf("%lld %lld\n",n,ans);
  if(n-1)ans++;
  printf("%lld\n",ans);
  return 0;
}
