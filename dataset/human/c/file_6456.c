// 16D8104007J Kanehiro Maho 兼弘真帆 2018年4月23日

#include<stdio.h>
int main(void){
  int n,i,j,max,min,ans;
  scanf("%d",&n);
  int r[n];
  for(i=0;i<n;i++){
    scanf("%d",&r[i]);
  }
  max=r[1]-r[0];
  min=r[0];
  for(i=1;i<n;i++){
    ans=r[i]-min;
    if(max<ans){
      max=ans;
    }
    if(r[i]<min){
      min=r[i];
    }
  }

  printf("%d\n",max);
  return 0;
}
