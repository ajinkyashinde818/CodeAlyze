#include<stdio.h>
#include<math.h>
 
int main(){
  int ans=0,N,count,K;
  
  scanf("%d %d\n",&N,&K);
  
  int h[N];
  
  for(count=0;count<N;count++){
  scanf("%d ",&h[count]);
  if(h[count]>=K){
     ans=ans+1; 
  }
      
  }
  
printf("%d",ans);  

  
  return 0;
  
}
