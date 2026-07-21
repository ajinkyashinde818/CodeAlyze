#include <stdio.h>

int main(){
  int n,r[200000],max,i,j,min;

  scanf("%d",&n);
  while(n<2||n>200000)  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&r[i]);
  }

  max=r[1]-r[0];
  min=r[0];
  for(j=1;j<n;j++){
      if((r[j]-min)>max) max=r[j]-min;
      if(min>r[j])min=r[j];
  }
  printf("%d\n",max);

  return 0;
}
