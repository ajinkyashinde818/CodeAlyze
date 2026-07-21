#include <stdio.h>
main(){
  int n;
  int rt[200000];
  int prof,x,minp;
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&rt[i]);
  }
  prof = rt[1]-rt[0];
  minp = rt[0];
  for(i=1;i<n;i++){    
    x = rt[i]-minp;
    if(prof<x){
        prof=x;
    }
    if(minp>rt[i]){
      minp = rt[i];
    }
  }
  printf("%d\n",prof);
}
