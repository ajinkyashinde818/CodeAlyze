#include<stdio.h>
int main(void){
  int a,b,k,tmp,i,j,num[100],cnt=0,l=0;
  scanf("%d %d %d",&a,&b,&k);
  if(a>b){
    tmp=a;
    a=b;
    b=tmp;
  }
  for(i=a;i>0;i--){
    if(a%i==0){
      num[cnt]=i;
      cnt++;
    }
  }
  for(i=0;i<cnt;i++){
    if(b%num[i]==0){
      l++;
    }
    if(l==k){
      break;
    }
  }
  printf("%d",num[i]);
  return 0;
}
