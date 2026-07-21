#include<stdio.h>
#include<math.h>
 
int main(){
  int i,r,n,min,max=-(pow(10,9));
 
  scanf("%d",&n);
  //r=(int *)malloc(sizeof(int)*n);
 
  scanf("%d",&min);
  max=max-min;
  for(i=1;i<n;i++){
    scanf("%d",&r);
    if(max<r-min) max=r-min;
    if(min>r){
      min=r;
      // printf("min:%d\n",min);
    }
  }
  printf("%d\n",max);
  return 0;
}
