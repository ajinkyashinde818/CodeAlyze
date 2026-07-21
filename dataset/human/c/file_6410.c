#include<stdio.h>

int main(){
  int i,n,v,minv,maxv;
  
  scanf("%d%d%d",&n,&minv,&v);
  maxv = v-minv;
  if(minv > v) minv = v;
   
  for(i=2;i<n;i++){
    scanf("%d",&v);
    if(maxv < (v-minv)) maxv = v-minv;
    if(minv > v) minv = v;
  }

  printf("%d\n",maxv);

  

  return 0;
}
