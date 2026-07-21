#include<stdio.h>
int main(void){
  int k,n,i,max=0,c;
  int a[200001];
  scanf("%d%d",&k,&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    c=a[(i+1)%n]-a[i];
    if(c<=0){
      c+=k;
    }
  //  printf("c=%d\n",c);
    if(max<c){
      max=c;
    //  printf("max=%d\n",c);
    }
  }
  printf("%d\n",k-max);
  return 0;
}
