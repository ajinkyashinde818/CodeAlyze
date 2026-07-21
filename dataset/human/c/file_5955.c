#include<stdio.h>
#include<stdlib.h>
 
int main(){
  int n,i,j,minv,maxv,*r;
 
  scanf("%d",&n);
 
  r = malloc(sizeof(int)*n);
 
  for(i = 0;i < n;i++){
    scanf("%d",&r[i]);
  }
 
  minv = r[0];
  maxv = r[1] - r[0];
  for(j = 1;j < n;j++){
    if(maxv > (r[j] - minv)){
      maxv = maxv;
    }
    else{
      maxv = r[j] - minv;
    }
 
    if(minv < r[j]){
      minv = minv;
    }
    else{
      minv = r[j];
    }
  }
 
  printf("%d\n",maxv);
 
  return 0;
}
