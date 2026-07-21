#include <stdio.h>
int main(){
  int r[200000],max,min,j,i,n;
  scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&r[i]);
    }
   
    min=r[0];
    max=r[1]-r[0];
    for(j=1;j<n;j++){
      if(max<r[j]-min) max=r[j]-min;

      if(min>r[j]) min=r[j];
    }
    printf("%d\n",max);

  return 0;
}
