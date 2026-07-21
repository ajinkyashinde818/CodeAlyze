#include<stdio.h>
#include<math.h>

char primes[300000];
int main(){
  int i,j,s=sqrt(300000)+1,n,sum;
  primes[0]=primes[1]=1;
  for(i=2;i<s;i++){
    if(primes[i]==0){
      for(j=2*i;j<300000;j+=i) primes[j]=1;
    }
  }
  do{
    scanf("%d",&n);
    if(!n) break;
    for(j=0,i=0,sum=0;i<n;i++){
      while(primes[j]) j++;
      sum+=j;
      j++;
    }
    printf("%d\n",sum);
  }while(1);
  return 0;
}
