#include<stdio.h>
#include<stdlib.h>
int main(){
  long long k;
  int n,i,j,count;
  scanf("%d%lld",&n,&k);
  int a[n+2],num[n+2],order[n+2];
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
    num[i]=0;
  }
  i=1;
  count=0;
  while(count<=n+3){
    if(num[i]==0){
      count+=1;
      num[i]++;
      order[count]=a[i];
      i=a[i];
    }
    else{
      order[0]=1;
      break;
    }
  }
  for(j=0;j<n;j++)
    if(order[j]==i){
      count-=j;
      break;
    }
  if(k-j>=0){
    k-=j;
    k=k%count;
    printf("%d\n",order[j+k]);
  }
  else
    printf("%d\n",order[k]);
  return 0;
}
