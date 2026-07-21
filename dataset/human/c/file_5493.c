#include<stdio.h>
#include<math.h>
#define MAX 10001

int GetPrime(int n){
 int i;

  for(i=2;i<=sqrt(n);i++)
   if(n % i ==0)return 0;

return n;
}


void FillPrime(int P[],int n){
 int i,j;

 for(i=1;i<=n;i++){
  if(P[i]==0){
    for(j=P[i-1]+1;j>=0;j++){
      if(GetPrime(j)!=0){
        P[i]=GetPrime(j);
        break;
      }
     }
   }
  }


return;
}

int main(){
 int n,i;
 int P[MAX]={0};
 int sum;

 P[1]=2;

 while(1){
  sum=0;
  scanf("%d",&n);
  if(n==0)break;

  FillPrime(P,n);

  for(i=1;i<=n;i++)sum+=P[i];

  printf("%d\n",sum);

 }

return 0;
}
