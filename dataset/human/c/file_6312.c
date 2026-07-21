#include<stdio.h>

int main(){
  int n,max,min,min_a;
  int i,check=0,mark=0;

  scanf("%d",&n);

  int R[n];
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }

  max = R[1];
  min = min_a = R[0];
  if(max-min>0) check=1;

  for(i=2;i<n;i++){
    if(!check){
      if((R[i]-R[i-1])>0){
        max = R[i];
        min = R[i-1];
        check = 1;
      }else if((max-min)<(R[i]-R[i-1])){
        max = R[i];
        min = R[i-1];
      }
    }else{
      if(max<R[i]) max = R[i];
      else if(min>R[i]){
        if(min_a>R[i]) min_a = R[i];
      }

      if((max-min)<(R[i]-min_a)){
        max = R[i];
        min = min_a;
      }
    }
  }

  printf("%d\n",max-min);
  return 0;
}
