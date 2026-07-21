#include<stdio.h>
#define M 1000000

int main(void){
  int i,j;
  int num[M];
  int n,s;

  num[0]=0;
  for(i=1;i<M;i++)
    num[i]=1;
  for(i=1;i<M;i++)
    if(num[i]==1){
      for(j=i;j<M;j+=i+1)
        num[j]=0;
      num[i]=1;
    }

  for(;;){
    scanf("%d",&n);
    if(n==0)
      break;

    s=0;
    for(i=1,j=0;j<n;i++)
      if(num[i]==1){
        s+=i+1;
        j++;
      }

    printf("%d\n",s);
  }

  return 0;
}
