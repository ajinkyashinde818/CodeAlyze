#include<stdio.h>

int main(){
int K,S,X,way=0,n;
scanf("%d %d",&K,&S);
for(X=K;X>=0;X--){
   n=S-X;
   if(n>=0 && n<=2*K){
      if(n<=K){
         way=way+n+1;
      }else{
         way=way+n+1-2*(n-K);
      }
   }
}
printf("%d",way);
return 0;
}
