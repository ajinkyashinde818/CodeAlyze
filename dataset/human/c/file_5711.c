#include <stdio.h>
int main(){
  int i,n,j,max,r[200000];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&r[i]);
  max=r[1]-r[0];
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(r[i]>r[j]){
	i=j;
	continue;
      }
      if(r[j]-r[i]>max)max=r[j]-r[i];
    }
  }
  printf("%d\n",max);
  return 0;
}
