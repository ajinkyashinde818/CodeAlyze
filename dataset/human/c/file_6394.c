#include <stdio.h>


 
int main(){
  int i,j,n,R[200000];
  int dai,syo;
 
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }
 //?????????
    syo = R[0];
    dai = R[1]-R[0];

    for(i=1;i<n;i++){
      if(R[i]-syo > dai) dai = R[i]-syo;
      if(R[i] < syo) syo = R[i];
    }
 
  printf("%d\n",dai);
  return 0;
}
