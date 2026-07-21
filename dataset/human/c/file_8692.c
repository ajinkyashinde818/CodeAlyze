#include <stdio.h>
int main(void){
  int n=0;
  int x[100001]={};
  int done[100001]={};
  scanf("%d",&n);
  for(int i=0;i<n;i++){
      scanf("%d",&x[i]);
      x[i]--;
  }
  int pos=0;
  int count=0;
  int imp=0;
  done[0]++;
  
  while(pos!=1){
      pos=x[pos];
      if(done[pos]==0){
          done[pos]++;
          count++;
      }else{
          imp++;
          break;
      }
  }
  
  if(imp==0){
      printf("%d\n",count);
  }else{
      printf("-1\n");
  }
 
  return 0;
}
