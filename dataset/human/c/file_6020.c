#include <stdio.h>
#include <stdlib.h>
#define l 200000
#define L 1000000000
#define s 2
#define S 1

int main(){

  int C[l],i,big=0,n,oum;

  scanf("%d",&n);

  if(s<=n&&n<=l){
    i=0;
    while(i<n){
      scanf("%d",&C[i]);
      if(S>C[i]||C[i]>L){
	exit(1);
      }
      i++;
    }
    big=C[i-1];
    oum=C[i-1]-C[i-2];

    i=n-2;
    while(i>=0){
      if(big<C[i]&&i!=0){
	big=C[i];
      }
      if(oum<big-C[i]&&C[i]!=big){
	oum=big-C[i];
      }
      i--;
    }
  }
  else{
    exit(1);
  }

  printf("%d\n",oum);
  return 0;
}
