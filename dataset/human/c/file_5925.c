#include<stdio.h>


int main(void){
  int i,N;
  int maxv=-1000000000;

  scanf("%d",&N);

  int array[N],j,minv;

  for(i=0;i<N;i++){
    scanf("%d",&array[i]);
  }



  
  minv=array[0];
  for(i=1;i<N;i++){
    if(maxv>=array[i]-minv){maxv=maxv;}
    else {maxv=array[i]-minv;}


    if(minv>=array[i]){minv=array[i];}
    else {minv=minv;}
  }

  printf("%d\n",maxv);
  return 0;
}
