#include<stdio.h>
int main(){
  int a,b,c,i,j,n[100],k=0;
  scanf("%d%d%d",&a,&b,&c);
  if(a<b){
    j=b;
  }else{
    j=a;
  }
  for(i=1;i<=j;i++){
    if(a%i==0&&b%i==0){
      n[k]=i;
      k++;
    }
  }
  c=k-c;
  printf("%d\n", n[c]);
  return 0;
}
