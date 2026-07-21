#include<stdio.h>
int main()
{
long long int n,m,i;
scanf("%lld %lld",&n,&m);
  long long int ans[n+1],a[m],sw;
  sw=0;
  ans[0]=1;
  
  if(m>0){
  for(i=0;i<m;++i)
  {scanf("%lld",&a[i]);}
  
  if(a[sw]==1) {ans[1]=0;
               sw++;}
  else ans[1]=1;
  
  for(i=2;i<=n;++i)
  {
  if(i==a[sw]) {ans[i]=0;
                sw++;}
   else
   {
   ans[i]=(ans[i-1]+ans[i-2])%1000000007;
   }
  }
  printf("%lld",ans[n]);
  }
  
  else if(n==1) printf("1");
  
  else{
  ans[0]=1;
  ans[1]=1;
  
    for(i=2;i<=n;++i)
  {ans[i]=(ans[i-1]+ans[i-2])%1000000007;
  }
    
  printf("%lld",ans[n]);
  }
return 0;}
