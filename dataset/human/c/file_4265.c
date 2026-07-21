#include <stdio.h>

long pp[100001];

long p(int w) {
  
   if (pp[w]>0) return pp[w];
   pp[w]=(p(w-1)+p(w-2))%1000000007;
   return pp[w];
}

int main(){
   int n,m,a[100000],i,j,w;
   long ans;
    
   scanf("%d %d",&n,&m);
   for (i=0;i<m;i++) scanf("%d",&a[i]);
   pp[1]=pp[2]=1;
   for (i=3;i<=n;i++) pp[i]=0;
   ans=1;j=0;
   for (i=0;i<m;i++) {
      w=a[i]-j;
      if (w==0) {
         ans=0;
         break;
      }
      ans=(ans*p(w))%1000000007;
      j=a[i]+1;
   }
   w=n-j+1;
   if (w>0) ans=(ans*p(w))%1000000007;
   else     ans=0;
   printf("%d\n",ans);
   return 0;
}
