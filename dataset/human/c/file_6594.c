#include<stdio.h>

int main(){

  int n,i,j,max,mini,R[200000];

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&R[i]);

  max=R[1]-R[0];
  mini=R[0];

  for(j=2;j<n;j++){
    if(mini > R[j-1])mini=R[j-1];
    if(max < R[j]-mini)max=R[j]-mini;
  }
    

  printf("%d\n",max);

  return 0;
}
