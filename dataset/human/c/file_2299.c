#include<stdio.h>
int main(){
  int i,n,k,s,ans;
  scanf("%d %d %d\n",&n,&k,&s);
  if(s==1000000000){
    for(i=0;i<n;i++){
    if(i<k){
      ans=s;
    }
    else{
      ans=s-1;
    }
    if(i==0){
      printf("%d",ans);
    }
    else{
      printf(" %d",ans);
    }
  }
    return 0;
  }
  for(i=0;i<n;i++){
    if(i<k){
      ans=s;
    }
    else{
      ans=s+1;
    }
    if(i==0){
      printf("%d",ans);
    }
    else{
      printf(" %d",ans);
    }
  }
  printf("\n");
  return 0;
}
