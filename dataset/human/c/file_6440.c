#include<stdio.h>
#include<stdlib.h>


int main(){

  int n,i,j,*a,maxi,mini;
  scanf("%d",&n);

  a=(int *)malloc(n*sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);

  }
  mini=a[0];
  maxi=a[1]-a[0];
  for(j=1;j<n;j++){
    if(maxi<a[j]-mini)maxi=a[j]-mini;
    if(mini>a[j])mini=a[j];
  }
  printf("%d\n",maxi);


  return 0;

}
