#include <stdio.h>


int maxprofit(int);
int main(){
  int n,max;


  scanf("%d",&n);
  max=maxprofit(n);
  printf("%d\n",max);


  return 0;
}

int maxprofit(int n){

  int i,j,r[n];
  int max,min;

  for(i=0;i<n;i++)
    scanf("%d",&r[i]);

  max=r[1]-r[0];
  min=r[0];
    
    for(j=1;j<n;j++){
      if(max<r[j]-min)max=r[j]-min;
      if(min>r[j])min=r[j];

  }
  return max;
}
