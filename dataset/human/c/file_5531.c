#include<stdio.h>
int main(void)
{
  int sosuu[10001];
  int i,j,k,l,n,sum,flag;
  k=2;
  sosuu[0]=2;
  sosuu[1]=3;
  for(i=5;i<=120000;i+=2){
    flag=0;
    for(j=3;j<i;j+=2){
      if(i%j==0){
	flag=1;
	break;
      }
    }
    if(flag==0){
      sosuu[k]=i;
      k++;
    }
    if(k==10000){
      break;
    }
  }
  while(scanf("%d",&n)!=EOF){
    sum=0;
    if(n==0){
      break;
    }
    for(l=0;l<n;l++){
      sum+=sosuu[l];
    }
    printf("%d\n",sum);
  }
  return 0;

}
