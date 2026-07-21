#include<stdio.h>
int main(){
  int n,i,j,k,a=1,r[100010]={};
  int d[1010][1010];
  scanf("%d",&n);
  for(i=0;i*(i-1)/2<n;i++);
  if(i*(i-1)/2>n){
    printf("No\n");
    return 0;
  }
  printf("Yes\n%d\n",i);
  for(j=0;j<i;j++){
    for(k=j+1;k<i;k++){
      d[j][r[j]++]=a  ;
      d[k][r[k]++]=a++;
    }
  }
  for(j=0;j<i;j++){
    printf("%d",r[j]);
    for(k=0;k<r[j];k++)printf(" %d",d[j][k]);
    printf("\n");
  }
  return 0;
}
