#include<stdio.h>
#include<limits.h>
int main(){
  int i,j;
  int n=0,d=0,x=0;
  scanf("%d",&n);
  int a[n];
  int eat[n],ans=0;
  for(i=0;i<n;i++){
    eat[i]=0;
  }
  scanf("%d%d",&d,&x);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    if(a[i] != 0){
      // printf("OK\n");
      eat[i]=(d-1)/a[i]+1;
    }
    else{
      // printf("a\n");
      eat[i]=0;
    }
    // printf("b\n");
    ans+=eat[i];
  }
  ans+=x;
  printf("%d\n",ans);
  return 0;
}
