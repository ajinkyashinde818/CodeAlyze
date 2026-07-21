#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
 long long n,k;
 scanf("%lld%lld",&n,&k);

 long long a[n];
 long long b;
 for(b=0;b<n;b++)
  scanf("%lld",&a[b]);

 long long memo[n+1],j=0,ok=0,m=k;
 long long point=1,cnt=0,ans=1,i;
 memo[1]=0;
  
 for(i=2;i<=n;i++)
   memo[i]=k+1;
  
 for(i=1;i<=k;i++){
  ok=0;
  point=a[point-1];
 // printf("point %lld\n",point);
  if(memo[point]!=k+1){
  // printf("%lld %lld %lld\n",point,i,memo[point]);
   j=memo[point];
   k=(k-j)%(-j+i);
 // printf("j %lld k %lld\n",j,k);
   ok=1;break;
  }
  if(ok)break;
  memo[point]=i;
 // printf("memo[point] %lld\n",memo[point]);
 }

 for(i=1;i<=j+k;i++)
   ans=a[ans-1];

 printf("%lld\n",ans);

return 0;}
