#include<stdio.h>
 
int main(){
   int i,n,ans=0;
   scanf("%d", &n);
   int a[n],b[n],c[n-1];
   for(i=0;i<n;i++){
   	scanf("%d ", &a[i]);
    a[i] = a[i] - 1;
   }
   for(i=0;i<n;i++){
   	scanf("%d ", &b[i]);
   }
   for(i=0;i<n-1;i++){
   	scanf("%d ", &c[i]);
   }
   for(i=0;i<n;i++){
   	ans = b[a[i]] + ans;
    if(i<n-1){
     if(a[i]+1==a[i+1]){
     	ans = c[a[i]] + ans;
     }
    }
   }
   printf("%d",ans);
   return 0;
}
