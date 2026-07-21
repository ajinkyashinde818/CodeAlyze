#include<stdio.h>

int main(){
  int n,ans=0;
  scanf("%d",&n);
  int d1[n+1],d2[n+1];
  for(int i=1;i<=n;i++){
    scanf("%d %d",&d1[i],&d2[i]);
    if(d1[i]==d2[i]){
      ans+=1;
      if(ans==3){
        printf("Yes");
        return 0;
      }
    }else{
      ans=0;
    }
  }
  
  printf("No");
  return 0;
  
}
